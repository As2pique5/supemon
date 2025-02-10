CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/player.c src/supemon.c src/battle.c src/shop.c src/save.c src/actions.c src/center.c
OBJ = $(SRC:.c=.o)
TARGET = supemon

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)