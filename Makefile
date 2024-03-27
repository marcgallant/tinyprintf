# Simple Makefile

# Compilers vars
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic

SRC=src/tinyprintf.c main.c
OBJ=$(SRC:.c=.o)

TEST=tests/str_revert.c \
     tests/disp_str.c \
     tests/my_itoa_base.c \
     tests/basics.c

OBJ_TEST= $(TEST:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) -o tinyprintf $(OBJ)

check: $(OBJ) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o tinyprintf $(OBJ) $(OBJ_TEST)
	./tinyprintf

clean:
	$(RM) $(OBJ_TEST) $(OBJ) tinyprintf

# END Makefile
