CFLAGS = -Wall -g
OBJ = linkedlist.o pipesim.o fileio.o
EXEC = pipesim
CC = gcc

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

listtest.o : listtest.c linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c listtest.c

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	rm -f $(EXEC) $(OBJ)
