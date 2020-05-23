# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lambrozi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:44:53 by lambrozi          #+#    #+#              #
#    Updated: 2020/05/23 13:31:05 by lambrozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

SDIR = ./src
ODIR = ./obj
IDIR = ./include
TDIR = ./test

_SRC = ft_printf.c
SRC = $(addprefix $(SDIR)/,$(_SRC))

OBJ = $(addprefix $(ODIR)/,$(_SRC:.c=.o))

CC = gcc
C_FLAGS = -Wall -Werror -Wextra -I $(IDIR)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a ./$@
	ar rc $@ $^
	ranlib $@

%(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(ODIR)
	$(CC) $(C_FLAGS) -g -o $@ -c $< 

bonus: fclean all

run:
	./$(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(ODIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

norm:
	norminette $(SDIR)

re: fclean all
