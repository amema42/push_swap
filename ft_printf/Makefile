# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amema <amema@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 14:32:00 by amema             #+#    #+#              #
#    Updated: 2023/10/03 14:32:01 by amema            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_hex.c\
		ft_putnbr.c\
		ft_putptr.c\
		ft_printfutils.c\
		ft_printf.c\

OBJECTS = ${SRCS:.c=.o}
COMPILER = gcc
CFLAGS = -Wall -Werror -Wextra
LIBRARY_NAME = libftprintf.a

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJECTS}
	ar rcs ${LIBRARY_NAME} ${OBJECTS}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${LIBRARY_NAME}

re: fclean all
