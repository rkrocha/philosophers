# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:12:55 by rkochhan          #+#    #+#              #
#    Updated: 2022/03/07 09:53:19 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

SRCS_DIR		= ./src
OBJS_DIR		= ./obj
INCLUDES_DIR	= ./includes

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
CDEBUG			= -g -fsanitize=address
LFLAGS			= -pthread
IFLAGS			= -I$(INCLUDES_DIR)

RM				= rm -f
NORM			= norminette

INCLUDES_FILES	= philo.h ft_bool.h
INCLUDES		= $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

SRCS			= philo.c

OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

# **************************************************************************** #
#                                   BUILD                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS) $(LFLAGS)
	@ echo "Made $(value NAME)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@ mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(IFLAGS) $(LFLAGS)

debug: $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(CDEBUG) -o $(NAME) $(OBJS) $(IFLAGS) $(LFLAGS)
	@ make -s clean
	@ echo "Made $(value NAME) for debugging"

test: debug
	@ sh ../test.sh

.PHONY: all debug test

# **************************************************************************** #
#                                   CLEAN                                      #
# **************************************************************************** #

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(NAME)
	@ rm -rf $(OBJS_DIR)

re: fclean all

.PHONY: clean fclean re
