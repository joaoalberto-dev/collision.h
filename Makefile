CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

all: test

test: test.c collision.h
	$(CC) $(CFLAGS) -o test test.c


run-test: test
	./test

clean:
	rm -f example test

.PHONY: all run-test clean
