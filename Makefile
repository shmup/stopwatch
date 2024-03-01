CC=gcc
CFLAGS=-Wall -O3

stopwatch: stopwatch.c
	$(CC) $(CFLAGS) stopwatch.c -o stopwatch -lrt
