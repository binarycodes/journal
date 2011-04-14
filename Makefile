CC=g++
CFLAGS=-c -Wall -pedantic -pedantic-errors

all: journal

journal: main.o datetime.o 
	$(CC) -o journal main.o datetime.o

main.o: main.cpp datetime.h
	$(CC) $(CFLAGS) main.cpp

datetime.o: datetime.h	
	$(CC) $(CFLAGS) datetime.cpp

clean:
	rm *.o journal

