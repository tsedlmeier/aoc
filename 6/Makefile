CFLAGS= -g -Wextra -Wall

.PHONY: all

all: 1 2

1: 1.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

2: 2.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -rf 1 2
