CC=clang
CFLAGS=-Wall -Wextra -Werror -pedantic

all: main.o intakethread.o procthread.o ring_buffer.o event_address_list.o event_ring_buffer.o intake_ring_buffer.o
	$(CC) $(CFLAGS) main.o intakethread.o procthread.o ring_buffer.o event_address_list.o event_ring_buffer.o intake_ring_buffer.o -o ProjectVigilence
	make clean 
	clear
	./ProjectVigilence

main.o: main.c
	$(CC) $(CFLAGS) -pthread -c main.c


intakethread.o: THREADS/DATA_INTAKE/dataIntakeThread.c 
	$(CC) $(CFLAGS) -pthread -c THREADS/DATA_INTAKE/dataIntakeThread.c -o intakethread.o

procthread.o: THREADS/DATA_PROCESSING/dataProcessingThread.c
	$(CC) $(CFLAGS) -pthread -c THREADS/DATA_PROCESSING/dataProcessingThread.c -o procthread.o

ring_buffer.o: DATA_STRUCTURES/ring_buffer.c
	$(CC) $(CFLAGS) -c DATA_STRUCTURES/ring_buffer.c -o ring_buffer.o

event_address_list.o: DATA_STRUCTURES/EVENT_RING_BUFFER/event_address_list.c
	$(CC) $(CFLAGS) -c DATA_STRUCTURES/EVENT_RING_BUFFER/event_address_list.c -o event_address_list.o

event_ring_buffer.o: DATA_STRUCTURES/EVENT_RING_BUFFER/event_ring_buffer.c
	$(CC) $(CFLAGS) -c DATA_STRUCTURES/EVENT_RING_BUFFER/event_ring_buffer.c -o event_ring_buffer.o

intake_ring_buffer.o: DATA_STRUCTURES/INTAKE_THREAD_BUFFER/intake_ring_buffer.c
	$(CC) $(CFLAGS) -c DATA_STRUCTURES/INTAKE_THREAD_BUFFER/intake_ring_buffer.c -o intake_ring_buffer.o


clean:
	rm -f *.o 
