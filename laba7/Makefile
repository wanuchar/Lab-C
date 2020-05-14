CC=gcc
CFLAGS= -pedantic -std=c89 -Wall

.PHONY: build run clean

all: build

build: ex

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

BuyerDataBase.o: BuyerDataBase.c
	$(CC) $(CFLAGS) -c BuyerDataBase.c

CarDataBase.o: CarDataBase.c
	$(CC) $(CFLAGS) -c CarDataBase.c

ex: main.o BuyerDataBase.o CarDataBase.o 
	$(CC) $(CFLAGS) -o ex main.o BuyerDataBase.o CarDataBase.o

run: ex
	./ex

clean:
	rm -rf *.o *.txt ex