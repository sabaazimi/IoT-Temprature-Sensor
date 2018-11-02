CC=gcc
CFLAGS=-Wall -pedantic 
main: main.o
	$(CC) $(CFLAGS) main.o -o main
	
main.o: main.c 
	$(CC) $(CFLAGS) -c main.c
clean:
	rm *.o main
