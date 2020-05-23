# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 14:26:48 by lambrozi          #+#    #+#              #
#    Updated: 2020/05/23 16:52:40 by lambrozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= run

LIBFTPRINTF_DIR	= ..
LIBFTPRINTF	= $(LIBFTPRINTF_DIR)/libftprintf.a
LIBFT_DIR	= ../libft

CC		= gcc
CC_FLAGS	= -g -Wall -Wextra -Werror \
		  -I$(LIBFT_DIR) \
		  -I$(LIBFTPRINTF_DIR)/include \
		  -L$(LIBFT_DIR) \
		  -L$(LIBFTPRINTF_DIR) \
		  -lft \
		  -lftprintf

SDIR		= .
SRC		= $(SDIR)/test.c


all: $(NAME)
	./$(NAME)

$(NAME): $(SRC) $(LIBFTPRINTF)
	$(CC) $< $(CC_FLAGS) -o $@

$(LIBFTPRINTF):
	make -C $(LIBFTPRINT_DIR)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all
