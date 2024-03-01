CC=gcc
CFLAGS=-Wall -O3

stopwatch: stopwatch.c
	$(CC) $(CFLAGS) stopwatch.c -o stopwatch -lrt

monitor: stopwatch
	@./stopwatch & \
	echo $$! > stopwatch.pid; \
	trap 'kill $$(cat stopwatch.pid) && rm stopwatch.pid' EXIT; \
	top -p $$(cat stopwatch.pid)
