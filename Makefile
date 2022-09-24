# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 13:06:47 by jchamorr          #+#    #+#              #
#    Updated: 2022/09/19 19:07:57 by jchamorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c\
		utils.c

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc -fsanitize=address -g3
FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(FLAGS) $(LIBFT) $^ -o $@
	@echo "Compiling Pipex..."

%.o : %.c pipex.h
	@$(CC) $(FLAGS) -c $< -o $@


clean:
	@$(RM) $(OBJS)
	@make clean -C libft/

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY:	all clean fclean re