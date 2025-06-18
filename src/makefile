CC=clang
CFLAGS=-Wall -Wextra -Werror -pedantic



all: main.o
	$(CC) $(CFLAGS) main.o -o ProjectVigilence
	make clean 
	clear
	./ProjectVigilence
main.o: main.cpp
	$(CC) $(CFLAGS) -pthread -c main.cpp

clean:
	rm -f *.o 
