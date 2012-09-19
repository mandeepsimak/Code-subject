OBJ = main.o subject.o 		                       		# target
OBJ1 = Roll_main.o rollno.o
CC = g++									# compiler variable
DEBUG = -g									# debugging flag 
CFLAGS = -Wall -c $(DEBUG)							# linking flag
LFLAGS = -Wall $(DEBUG)					  	  # flag used in compiling and creating object files	

# All targets 
all: subject run rollno run-rollno

# target to generate executable file.
subject: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o subject

# target to run executable file	
run: 
	./subject > output.txt

rollno: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o rollno

# target to run executable file	
run-rollno: 
	./rollno > Rollno.txt

# dependencies of seat_main.cpp
main.o: main.cpp subject.h
	$(CC) $(CFLAGS) main.cpp

# dependencies of seat_functions.cpp
subject.o: subject.cpp subject.h
	$(CC) $(CFLAGS) subject.cpp 

# dependencies of seat_main.cpp
Roll_main.o: Roll_main.cpp rollno.h
	$(CC) $(CFLAGS) Roll_main.cpp

# dependencies of seat_functions.cpp
rollno.o: rollno.cpp rollno.h
	$(CC) $(CFLAGS) rollno.cpp 

# to destroy all the object and exectuable file
clean:
	rm -f *.o subject output.txt Rollno.txt rollno 

