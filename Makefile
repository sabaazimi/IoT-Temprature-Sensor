CC=gcc
CFLAGS=-Wall -pedantic 
main: main.o libmyifttt.a
	$(CC) $(CFLAGS) main.o -L. -lmyifttt -lcurl -o main
	
main.o: main.c 
	$(CC) $(CFLAGS) -c main.c
	
libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<
	
clean:
	rm *.o main
