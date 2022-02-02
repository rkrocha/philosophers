# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:12:55 by rkochhan          #+#    #+#              #
#    Updated: 2022/02/02 10:30:40 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

SRCS_DIR		= ./src
OBJS_DIR		= ./obj
INCLUDES_DIR	= ./includes

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
CDEBUG			= -g -fsanitize=address
LFLAGS			=
IFLAGS			= -I$(INCLUDES_DIR)

RM				= rm -f
NORM			= norminette

INCLUDES_FILES	= philo.h
INCLUDES		= $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

SRCS			= philo.c

OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

# **************************************************************************** #
#                                   MAKE                                       #
# **************************************************************************** #

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) $(IFLAGS)
	@ echo "Made $(value NAME)"

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@ mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(IFLAGS)

.PHONY: all

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

# **************************************************************************** #
#                                NORMINETTE                                    #
# **************************************************************************** #

norm:
	@ $(NORM) $(SRCS_DIR)/*.c $(INCLUDES_DIR)/*.h

.PHONY: norm
