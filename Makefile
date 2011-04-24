CC=g++
CFLAGS=-c -Wall -pedantic -pedantic-errors
LINKER = -lboost_program_options -lreadline

all: journal

journal: main.o datetime.o journal.o utility.o note.o cinterface.o optionparser.o
	$(CC) -o $@ $^ $(LINKER)

main.o: main.cpp datetime.h journal.h
	$(CC) $(CFLAGS) -o $@ $<

datetime.o: datetime.cpp datetime.h	
	$(CC) $(CFLAGS) -o $@ $<

journal.o: journal.cpp journal.h
	$(CC) $(CFLAGS) -o $@ $<

utility.o: utility.cpp utility.h
	$(CC) $(CFLAGS) -o $@ $<

note.o: note.cpp note.h datetime.h
	$(CC) $(CFLAGS) -o $@ $<

cinterface.o: cinterface.cpp cinterface.h
	$(CC) $(CFLAGS) -o $@ $<

optionparser.o: optionparser.cpp optionparser.h
	$(CC) $(CFLAGS) -o $@ $<


.PHONY: clean

clean:
	-rm -f *.o journal

