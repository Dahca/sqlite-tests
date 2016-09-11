CC=gcc
LFLAG=-lsqlite3

simple_connect_test: simple_connect_test.c
		$(CC) -o simple_connect_test simple_connect_test.c $(LFLAG)

clean:
		rm simple_connect_test
