# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 13:06:47 by jchamorr          #+#    #+#              #
#    Updated: 2022/06/24 10:48:08 by jchamorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc -fsanitize=address -g3
FLAGS = -Wall -Wextra -Werror

RM = rm -rf
SAN = -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@make -C libft/
	@$(CC) $(FLAGS) $(LIBFT) $^ -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C libft/

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re