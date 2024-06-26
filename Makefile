# Simple Makefile

# Compilers vars
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic
LDFLAGS=-fsanitize=address -g
LDLIBS=-lcriterion

SRC=src/tinyprintf.c
OBJ=$(SRC:.c=.o)

TEST=tests/disp_str.c \
     tests/my_itoa_base.c \
     tests/basics.c

OBJ_TEST= $(TEST:.c=.o)

all: $(OBJ)

check: $(OBJ) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o tinyprintf $(OBJ) $(OBJ_TEST)
	./tinyprintf

clean:
	$(RM) $(OBJ_TEST) $(OBJ) tinyprintf

# END Makefile
