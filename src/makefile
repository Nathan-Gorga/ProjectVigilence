CC=clang
CFLAGS=-Wall -Wextra -Werror -pedantic

all: main.o intakethread.o procthread.o
	$(CC) $(CFLAGS) main.o intakethread.o procthread.o -o ProjectVigilence
	make clean 
	clear
	./ProjectVigilence

main.o: main.c
	$(CC) $(CFLAGS) -pthread -c main.c


intakethread.o: THREADS/DATA_INTAKE/dataIntakeThread.c 
	$(CC) $(CFLAGS) -pthread -c THREADS/DATA_INTAKE/dataIntakeThread.c -o intakethread.o

procthread.o: THREADS/DATA_PROCESSING/dataProcessingThread.c
	$(CC) $(CFLAGS) -pthread -c THREADS/DATA_PROCESSING/dataProcessingThread.c -o procthread.o



clean:
	rm -f *.o 
