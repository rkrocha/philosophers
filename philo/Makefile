# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:12:55 by rkochhan          #+#    #+#              #
#    Updated: 2022/03/09 11:53:08 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
CDEBUG			= -g -fsanitize=address
INCLUDE			= philo.h ft_bool.h
IFLAGS			= -I.
LFLAGS			= -pthread

RM				= rm -rf
NORM			= norminette

SRC				= philo.c \
					parser.c \
					ft_atoi.c \
					ft_isspace.c \
					ft_strchr.c \
					ft_strignore.c

OBJ				= $(SRC:.c=.o)

# **************************************************************************** #
#                                   BUILD                                      #
# **************************************************************************** #

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(IFLAGS) $(LFLAGS)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(IFLAGS) $(LFLAGS)
	@ echo "Made $(value NAME)"

all: $(NAME)

debug:
	$(CC) $(CFLAGS) $(CDEBUG) -o $(NAME) $(OBJ) $(IFLAGS) $(LFLAGS)
	@ make -s clean
	@ echo "Made $(value NAME) for debugging"

test: #debug
	@ make -s -C ../tests
	@ sh ../tests/philo_tester.sh

.PHONY: all debug test

# **************************************************************************** #
#                                   CLEAN                                      #
# **************************************************************************** #

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
