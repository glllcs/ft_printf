# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lambrozi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:44:53 by lambrozi          #+#    #+#              #
#    Updated: 2020/09/03 10:15:43 by lambrozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

IDIR		= ./include
TDIR		= ./test

LIBFT_DIR	= ./libft
LIBFT		= ${LIBFT_DIR}/libft.a

SDIR		= ./src
_SRC		=	ft_printf.c ft_get_identifiers.c ft_prepare.c \
				ft_nbr_aux.c ft_strfree.c ft_print_all.c ft_print_space.c
SRC		= $(addprefix $(SDIR)/,$(_SRC))

ODIR		= ./obj
OBJ		= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

CC		= gcc
C_FLAGS		=	\
			-I $(IDIR) \
			-I $(LIBFT_DIR) \
			-g
			#-L $(LIBFT_DIR) \
			#-lft

all: $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT_DIR)
	cp libft/libft.a ./$@
	ar rcs $@ $^
	ranlib $@

$(ODIR)/%.o: $(SDIR)/%.c $(LIBFT)
	mkdir -p $(ODIR)
	$(CC) $(C_FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: fclean all

run:
	./$(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(ODIR)
	make -C $(LIBFT_DIR) clean 

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(TDIR) fclean

norm:
	~/.norminette/norminette.rb $(SDIR) $(IDIR)
	#make -C $(LIBFT_DIR) norm 

re: fclean all

bonus: $(NAME)

test: all
	make -C $(TDIR)

