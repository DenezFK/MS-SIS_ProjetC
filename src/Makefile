CC = gcc
TARGET = main

SRC = main.c modeG.c modeL.c structure.c sha256.c md5.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	@clear && ./$(TARGET)

.PHONY: clean run
