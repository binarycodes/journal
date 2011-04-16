CC=g++
CFLAGS=-c -Wall -pedantic -pedantic-errors

all: journal

journal: main.o datetime.o journal.o utility.o
	$(CC) -o $@ $^

main.o: main.cpp datetime.h journal.h
	$(CC) $(CFLAGS) -o $@ $<

datetime.o: datetime.cpp datetime.h	
	$(CC) $(CFLAGS) -o $@ $<

journal.o: journal.cpp journal.h
	$(CC) $(CFLAGS) -o $@ $<

utility.o: utility.cpp utility.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	-rm -f *.o journal

