# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:12:55 by rkochhan          #+#    #+#              #
#    Updated: 2022/03/09 16:25:46 by rkochhan         ###   ########.fr        #
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
					time.c \
					ft_atoi.c \
					ft_isspace.c \
					ft_strchr.c \
					ft_strignore.c

OBJ				= $(SRC:.c=.o)

# **************************************************************************** #
#                                   BUILD                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(IFLAGS) $(LFLAGS)
	@ echo "Made $(value NAME)"

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(IFLAGS) $(LFLAGS)

debug:
	$(CC) $(CFLAGS) $(CDEBUG) -o $(NAME) $(SRC) $(IFLAGS) $(LFLAGS)
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
