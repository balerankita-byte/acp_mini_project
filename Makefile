CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lncurses -lm

TARGET = graphics_editor
SRC = graphics_editor.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
