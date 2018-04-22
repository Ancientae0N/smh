# Simple C Shell Makefile

CC = gcc
CFLAGS  = -Wall -g
OBJ = Hash.o

all: Hash

Hash: $(OBJ)
	$(CC) $(CFLAGS) -o Hash $(OBJ) 

%.o: %.c
	$(CC) $(CFLAGS) -c $<
