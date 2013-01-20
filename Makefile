CC      =   g++
CFLAGS  =   -c ${XFLAGS} ${INCDIRS}
LINKER  =   -lboost_program_options -lreadline
XFLAGS  =   -Wall -Wshadow -DDEBUG -Wredundant-decls -pedantic -pedantic-errors
INCDIRS =   -I${INC1}
INC1    =   ./includes


CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))




all: journal

journal: $(OBJ_FILES)
	$(CC) -o $@ $^ $(LINKER)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<


.PHONY: clean

clean:
	-rm -f obj/*.o journal
