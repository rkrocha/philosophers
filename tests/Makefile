CC	= gcc -Wall -Wextra -Werror -fsanitize=address -I../philo/includes/ -lrt -lm $@_test.c -o $@_test

TEST= ./$@_test -v; rm -f $@_test

EXEC= $(CC) && $(TEST)


all: parser

parser:
	$(EXEC)
