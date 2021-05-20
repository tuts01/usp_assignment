CFLAGS = -Wall -g
OBJ = linkedlist.o listtest.o
EXEC = test
CC = gcc

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

listtest.o : listtest.c linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c listtest.c

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	rm -f $(EXEC) listtest.o linkedlist.o
