CC = gcc
CFLAGS = -Wall -O2

TARGET = game
OBJS = main.o player.o enemy.o battle.o map.o

all: $(TARGET)

run: all
	./game

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) *.o
