CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=ex3.o
FLAGS= -Wall -g

all: stringProg	

stringProg: $(OBJECTS_MAIN) ex3.o 
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) ex3.o	
ex3.o: ex3.c ex3.h
	$(CC) $(FLAGS) -c ex3.c
main.o: main.c ex3.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a progmains stringProg