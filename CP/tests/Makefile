CC = gcc
CFLAGS = -Wall -O3 -lm
CPPFLAGS =

test: $(wildcard *.c)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

clean:
	rm labt test
