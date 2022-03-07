CC	= gcc -Wall -Wextra -Werror -fsanitize=address $@_test.c -o $@_test

TEST= ./$@_test; rm -f $@_test

EXEC= $(CC) && $(TEST)


all: parser

parser:
	$(EXEC)
