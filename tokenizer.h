#include <string.h>
#include <stdio.h>

#define SIZE 20

typedef struct commands {
	char result[SIZE][SIZE];
	int length;
}commands;

commands split (char input[SIZE]);
