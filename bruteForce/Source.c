#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// max length of a string and symbol set
#define MAX_LENGTH 3
// symbols/characters which will be used for generating word combinations
char symbols[] = "abcdefgh123";

char* symbolsPtr = symbols;
char** base = NULL;
int currentLength = 1, i, counter;

/**
Expand base array to length+1, and set all elements to first element from possible characters
list because array[length] is overflowed so we start with 1 element bigger array from the smallest
possible combination
*/
void expandArray(char** baseArray, char* symbols, int length) {
	baseArray = (char**)realloc(baseArray, sizeof(char*) * (length + 1));
	for (i = 0; i <= length; i++) {
		baseArray[i] = symbols;
	}
}

// Given the base pointer and length of string it prints the current base 
void printArray(char** baseArray, int len) {
	for (i = 0; i < len; i++) {
		putchar(*baseArray[i]);
	}
	putchar('\n');
}

int main() {

	base = (char**)malloc(sizeof(char*));
	const char* symbolsEnd = symbolsPtr + strlen(symbols);

	// while length of base is smaller or equal to given string length
	while (currentLength <= MAX_LENGTH) {
		while (symbolsPtr < symbolsEnd) {
			base[currentLength - 1] = symbolsPtr++;
			printArray(base, currentLength); // Combinations!
		}

		for (i = currentLength - 1, counter = 0; i >= 0; i--) {
			if (*base[i] == *(symbolsEnd - 1)) {
				counter++;
			}
			else break;
		}
		// if all positions have the highest character expand array for 1 because of the overflow 			
		if (counter == currentLength) {
			expandArray(base, symbols, currentLength);
			currentLength++;
		}
		// else "carry 1"
		else {
			base[currentLength - counter - 1]++;
			for (i = currentLength - 1; i >= currentLength - counter; i--) {
				base[i] = symbols;
			}
		}
		symbolsPtr = symbols;
	}
	free(base);
	return 0;
}