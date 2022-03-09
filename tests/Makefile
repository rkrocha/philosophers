NAME	= unit_tester
CC		= gcc
INCLUDE	= -I../philo/includes/
FLAGS	= -Wall -Wextra -Werror -fsanitize=address
LFLAGS	= -lrt -lm
RM		= /usr/bin/rm -f

EXEC	= $(CC) $(FLAGS) $(INCLUDE) $(LFLAGS) $(NAME).c -o $(NAME) && ./$(NAME)

all:
	$(EXEC)

clean:
	$(RM) $(NAME)
