CFLAGS= -g -Wextra -Wall

.PHONY: all

all: bag bag3 db1 db2

bag: bag.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

bag: bag3.c
	gcc -std=c99 $(CFLAGS) $(LDFLAGS) $< -o $@

db1: bag.c
	gcc -std=c99 -g $(LDFLAGS) $< -o $@
	gdb $@

db2: bag3.c
	gcc -std=c99 -g $(LDFLAGS) $< -o $@
	gdb $@

clean:
	rm -rf bag bag3
