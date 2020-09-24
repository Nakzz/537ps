CC = gcc
CFLAGS = -Wall -pedantic -ggdb
OBJECTS = main.o argparser.o pid.o

537ps: $(OBJECTS)
	$(CC) $(CFLAGS) -o 537ps ${OBJECTS}

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

argparser.o: argparser.c argparser.h
	$(CC) $(CFLAGS) -c argparser.c

pid.o: pid.c pid.h 
	$(CC) $(CFLAGS) -c pid.c 

clean:
	rm -f $(OBJECTS) 537ps
