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

CFILES	= main.c  parse.c syntax.c lib.c operations/*.c

SRCS	= $(addprefix srcs/, ${CFILES})

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I include/ -I libft/includes/

HEADER	= push_swap.h

RM	= rm -f

all:	${NAME}

${NAME}:
	make -s -C libft
	${CC} ${CFLAGS} ${SRCS}  -Llibft -lft -o $@

clean:
	make clean -s -C libft
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	make fclean -s -C libft
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
