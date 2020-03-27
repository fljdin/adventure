# Header
CC = gcc
CFLAGS = -g -Wall -Isrc

TARGET ?= bin/console
SOURCES = $(shell find src/engine -name *.c)
OBJECTS = $(patsubst src/%.c,build/%.o,$(SOURCES))

TESTS = $(wildcard tests/*_test.c)
TST_TARGET = $(patsubst tests/%.c,bin/%,$(TESTS))

# Target build
.PHONY: build tests

all: build $(TARGET)

tests: build $(TST_TARGET)

$(TARGET): $(SOURCES:.c=.o)
	$(CC) -o $@ $(OBJECTS)

$(TST_TARGET): $(SOURCES:.c=.o)
	$(CC) -c -o $(patsubst bin/%,build/%.o,$@) $(patsubst bin/%,tests/%.c,$@)
	$(CC) -o $@ $(patsubst bin/%,build/%.o,$@) $(OBJECTS)

$(SOURCES:.c=.o): %o: %c
	$(CC) -c -o $(patsubst src/%,build/%,$@) $<

build:
	mkdir -p $(dir $(OBJECTS)) $(dir $(TARGET))

clean:
	rm -rf $(dir $(OBJECTS)) $(dir $(TARGET))
	find src -name *.o -delete

echo:
	@echo $(dir $(OBJECTS))