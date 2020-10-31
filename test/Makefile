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

NAME		= a.out

DEBG_DIR	= $(NAME).dSYM

LIBFTPRINTF_DIR	= ..
LIBFTPRINTF_IDIR = $(LIBFTPRINTF_DIR)/include
LIBFTPRINTF	= $(LIBFTPRINTF_DIR)/libftprintf.a
LIBFT_DIR	= ../libft
LIBFT_IDIR	= $(LIBFT_DIR)/include

CC		= gcc
CC_FLAGS	= -g -Wall -Wextra  \
		  -I$(LIBFT_IDIR) \
		  -I$(LIBFTPRINTF_IDIR) \
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
	$(RM) -rf $(DEBG_DIR)

re: fclean all
