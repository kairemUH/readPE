###############################################################################
###               University of Hawaii, College of Engineering
###               Lab 6 - readpe - SRE - Spring 2023
###
### readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
###
### @see     https://www.gnu.org/software/make/manual/make.html
###
### @file    Makefile
### @author Kai Matsusaka <kairem@hawaii.edu>
###############################################################################

TARGET = readpe

all: $(TARGET)

CC     = g++
CFLAGS = -Wall -Wextra $(DEBUG_FLAGS)

debug: DEBUG_FLAGS = -g -DDEBUG
debug: clean $(TARGET)

DosHeader.o: DosHeader.cpp DosHeader.hpp 
	$(CC) $(CFLAGS) -c DosHeader.cpp

FileHeader.o: FileHeader.cpp FileHeader.hpp 
	$(CC) $(CFLAGS) -c FileHeader.cpp

OptionalHeader32.o: OptionalHeader32.cpp OptionalHeader32.hpp 
	$(CC) $(CFLAGS) -c OptionalHeader32.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

readpe: main.o DosHeader.o FileHeader.o OptionalHeader32.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o DosHeader.o FileHeader.o OptionalHeader32.o

test: readpe
	./readpe catnap32.exe

clean:
	rm -f $(TARGET) *.o