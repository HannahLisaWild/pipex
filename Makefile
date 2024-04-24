# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawild <hawild@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 11:35:51 by hawild            #+#    #+#              #
#    Updated: 2024/04/22 13:29:31 by hawild           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = -Iincludes

SRCS = pipex.c utils.c 
		
OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

.c.o:		
			@gcc ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}



all: 		${NAME}

${NAME}: 	${OBJS}
						@make re -C ./libft
						@${CC} ${OBJS} -Llibft -lft -o ${NAME}
						@echo "\033[0;32mPipex compiled\033[0m"

clean: 
						@make clean -C ./libft
						@rm -f ${OBJS}
						@echo "\033[0;35mObjects removed\033[0m"

fclean: 	clean
						@make fclean -C ./libft
						@rm -f ${NAME}
						@echo "\033[0;36mEverything removed\033[0m"

re: 		fclean all

.PHONY:      all clean fclean re
