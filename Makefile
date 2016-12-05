CC		= gcc
PROG	= scan


$(PROG): scan.o parser.o
	$(CC) -o $(PROG) scan.o parser.o

scanner.o : scan.c
	$(CC) -c scan.c 

parser.o : parser.c
	$(CC) -c parser.c

.PHONY: clean

clean:
	rm -rf core $(PROG) *.o
