# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:12:55 by rkochhan          #+#    #+#              #
#    Updated: 2022/03/11 18:32:10 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -O3
CDEBUG			= -Wall -Wextra -Werror -g -fsanitize=address
INCLUDE			= philo.h ft_bool.h
IFLAGS			= -I.
LFLAGS			= -pthread

RM				= rm -rf
NORM			= norminette

SRC				= philo.c \
					parser.c \
					init.c \
					time.c \
					utils.c \
					ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isspace.c \
					ft_strchr.c \
					ft_strignore.c

OBJ				= $(SRC:.c=.o)

# **************************************************************************** #
#                                   BUILD                                      #
# **************************************************************************** #

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) -o $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

./%.o: ./%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(IFLAGS) $(LFLAGS)

debug:
	$(CC) $(CDEBUG) $(SRC) $(IFLAGS) $(LFLAGS) -o $(NAME)
	@ make -s clean
	@ echo "Made $(value NAME) for debugging"

test: #debug
	@ make -s -C ../tests

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
