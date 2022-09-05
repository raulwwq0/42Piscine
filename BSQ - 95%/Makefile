# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iperez-r <iperez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 08:56:13 by rauaguil          #+#    #+#              #
#    Updated: 2022/08/31 18:02:04 by iperez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	bsq
CC			= 	gcc
CFLAGS		= 	-Werror -Wall -Wextra
RM			= 	rm -f
SRCSDIR		= 	./srcs
SRCS		= 	${SRCSDIR}/main.c \
				${SRCSDIR}/histogram_solve.c \
				${SRCSDIR}/process_map.c \
				${SRCSDIR}/ft_atoi.c \
				${SRCSDIR}/memory_mgr.c \
				${SRCSDIR}/print.c \
				${SRCSDIR}/solve.c \
				${SRCSDIR}/transform_board.c \
				${SRCSDIR}/buffer_mgr.c \
				${SRCSDIR}/input_stdin.c \
				${SRCSDIR}/utils.c \
				${SRCSDIR}/create_board.c \
				${SRCSDIR}/checkers.c
OBJS		= 	${SRCS:.c=.o}

.c.o	: fclean
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -Iincludes

${NAME}	:	fclean ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean	:
		${RM} ${OBJS}
	
fclean	:	clean
		${RM} ${NAME}

.PHONY: clean fclean .c.o