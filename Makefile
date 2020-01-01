# Makefile

CC?=gcc
CFLAGS=-Wall -g
EXEC=advent

all: build

objects:
	cd src ; $(CC) $(CFLAFS) -c -o advent.o advent.c

build: objects
	cd src ; $(CC) $(CFLAGS) -o ../bin/$(EXEC) $(OBJS)

test: objects
	cd src ; $(CC) $(CFLAFS) -o ../bin/advent_test \
		advent.o advent_test.c ; \
	../bin/advent_test

clean:
	rm -f bin/$(EXEC)
