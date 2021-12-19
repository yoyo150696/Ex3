CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=ex3.o
FLAGS= -Wall -g

all: stringProg	
stringProg: $(OBJECTS_MAIN) libex3.a 
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) libex3.a
libex3.a: $(OBJECTS_LIB)
	$(AR) -rcs libex3.a $(OBJECTS_LIB)	
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
main.o: main.c my_mat.h  
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all

clean:
	rm -f *.o *.a progmains stringProg