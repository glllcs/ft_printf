# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lambrozi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:44:53 by lambrozi          #+#    #+#              #
#    Updated: 2020/05/23 09:45:20 by lambrozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

SDIR = src

ODIR = objs

IDIR = include

SOURCES = ft_printf.c main.c

SRC = $(addprefix $(SDIR)/,$(SOURCES))

OBJS = $(addprefix $(ODIR)/,$(SOURCES:.c=.o))

CC = gcc
C_FLAGS = -Wall -Werror -Wextra -I $(IDIR)

all: $(NAME)

$(NAME) : $(OBJS)
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
	rm -f $(OBJS)
	rm -rf $(ODIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

norm:
	norminette $(SDIR)

re: fclean all
