CC = gcc
CFLAGS = -g -Wall -Werror -pedantic-errors

all: test

test: test.o node.o linked_list.o
	$(CC) $(CFLAGS) test.o linked_list.o node.o -o test

test.o: test.c
	$(CC) $(CFLAGS) -c test.c
	
linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c

clean:
	rm -f test test.o linked_list.o node.o
