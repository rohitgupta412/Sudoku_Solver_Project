CC=gcc
CFLAGS=-Wall -Wextra -std=c11
SRC=src/main.c src/sudoku.c
all:
	$(CC) $(CFLAGS) -o main $(SRC)