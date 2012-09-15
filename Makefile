OBJ = main.o subject.o 		                       		# target
CC = g++									# compiler variable
DEBUG = -g									# debugging flag 
CFLAGS = -Wall -c $(DEBUG)							# linking flag
LFLAGS = -Wall $(DEBUG)					  	  # flag used in compiling and creating object files	

# All targets 
all: run

# target to generate executable file.
main: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o subject

# target to run executable file	
run: 
	./subject > output.txt

# dependencies of seat_main.cpp
main.o: main.cpp subject.h
	$(CC) $(CFLAGS) main.cpp

# dependencies of seat_functions.cpp
seat_functions.o: subject.cpp subject.h
	$(CC) $(CFLAGS) subject.cpp 

# to destroy all the object and exectuable file
clean:
	rm -f *.o subject output.txt 

