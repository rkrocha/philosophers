NAME	= unit_tester
CC		= gcc
INCLUDE	= -I../philo/
FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
LFLAGS	= -lrt -lm
RM		= /usr/bin/rm -f

EXEC	= $(CC) $(FLAGS) $(INCLUDE) $(LFLAGS) $(NAME).c -o $(NAME) && ./$(NAME)

all:
	$(EXEC)
	bash run_philo_tester.sh

clean:
	$(RM) $(NAME)
