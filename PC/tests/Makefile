OBJS = test_dinamic.o

PROGRAM = tests

CC ?= gcc
CCLD ?= gcc

CFLAGS += -O3 -Wall -lm
LDFLAGS = 

.PHONY: all clean
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJS)
	$(CCLD) -o $(PROGRAM) $(OBJS) $(LDFLAGS)

all: $(PROGRAM)

clean:
	rm -vf $(OBJS) $(PROGRAM)

