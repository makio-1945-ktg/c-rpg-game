CC = gcc
CFLAGS = -Wall -O2

TARGET = main
OBJS = main.o calc.o

all: $(TARGET)

run: all
	./main

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c calc.h
	$(CC) $(CFLAGS) -c main.c

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean:
	rm -f $(TARGET) *.o

