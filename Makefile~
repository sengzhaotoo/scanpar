CC		= gcc
PROG	= scan 

$(PROG): scan.o
	$(CC) -o $(PROG) scan.o

scanner.o : scan.c
	$(CC) -c scan.c

.PHONY: clean

clean:
	rm -rf core $(PROG) *.o
