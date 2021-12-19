CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=ex3.o
FLAGS= -Wall -g

all: libex3.a progmains	progmaind
progmains: $(OBJECTS_MAIN) libex3.a 
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) libex3.a
progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) ./libex3.so
libex3.so: $(OBJECTS_LIB)
	$(CC) -shared -o libex3.so $(OBJECTS_LIB)	
libex3.a: $(OBJECTS_LIB)
	$(AR) -rcs libex3.a $(OBJECTS_LIB)	
ex3.o: ex3.c ex3.h
	$(CC) $(FLAGS) -c ex3.c
main.o: main.c ex3.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a progmains stringProg