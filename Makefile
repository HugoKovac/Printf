# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 16:35:54 by hkovac            #+#    #+#              #
#    Updated: 2021/12/01 16:46:01 by hkovac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = libft.h
SRCS = ft_char.c ft_dec.c ft_dispatch.c ft_hex.c ft_printf.c ft_ptr.c ft_str.c ft_uns.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o: $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rsc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

lib: $(NAME) clean
	@echo Done

.PHONY: all clean fclean re bonus lib