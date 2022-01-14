# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 12:06:00 by tyuan             #+#    #+#              #
#    Updated: 2021/01/03 10:33:46 by tyuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c  parse.c syntax.c push_swap_medium.c calculate.c methods.c order_check.c operations/multi_ops.c operations/push.c operations/rotate.c operations/rrotate.c operations/swap.c

DIRSRC	= srcs

OBJS	= ${addprefix ${DIROBJ}/, ${SRCS:.c=.o}}

DIROBJ	= objs

LIBS	= -Llibft -lft

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

INCLUDE	= -I include/ -I libft/includes/

HEADER	= push_swap.h

RM	= rm -rf

all:	${NAME}

${NAME}: ${OBJS}
	make -s -C libft
	${CC} ${CFLAGS} ${INCLUDE} $^ ${LIBS} -o $@

${DIROBJ}:
	mkdir -p $@/operations

${DIROBJ}/%.o: ${DIRSRC}/%.c | ${DIROBJ}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	make clean -s -C libft
	${RM} ${DIROBJ}

fclean: clean
	make fclean -s -C libft
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
