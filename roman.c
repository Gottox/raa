/* Copyright (C) Enno Boland
 *
 * This file is released under the GPLv2.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256

int main (int argc, char **argv)
{
	if(argc < 2 || strcmp(argv[1],"-h") == 0) {
		printf("usage: %s arabian_numerals\n",argv[0]);
		exit(1);
	}
	
	/* Digits and their decimal values */
	char digits[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'  };
	int values[7]  = {  1,   5,   10,  50, 100, 500, 1000 };
	char *result = malloc(sizeof(char) * SIZE);
	result[0] = '\0';
	unsigned long size = SIZE;
	
	/* Countervariable */
	int priority = 7;
	
	/* The number which will be calculated as a roman number. */
	int number;
	sscanf(argv[1],"%d",&number);

	/* Helper variable and counter */
	int divide;

	/* Stringlength of the result to proof that we dont get an buffer overflow. */
	int length;

	while(--priority != -1) {

		/* Set the string length */
		length = strlen(result);

		/* Reallocate new space if necessary */
		if(size - length < 5) {
			size += SIZE;
			result = realloc(result, size);
		}

		/* How much characters will be added? (only for the last else) */
		divide=number/values[priority];

		/* If the smaller digit plus the number is greater than the bigger digit
		 * use the subtractive notation (Write IX instead of VIV) */
		if(priority+1 < 7 && priority-1 >= 0 && (number+values[priority-1]) / values[priority+1] != 0) {
			result[length] = digits[priority-1];
			result[length+1] = digits[priority+1];
			result[length+2] = '\0';
			number = number % (values[priority+1] - values[priority-1]);
		}
		/* Also use subtractive notation if the number of the character which will be added is 4. */
		else if(priority+1 < 7 && divide == 4) {
			result[length] = digits[priority];
			result[length+1] = digits[priority+1];
			result[length+2] = '\0';
			number=number%values[priority];
		}
		/* else add the number as it. */
		else {
			while(--divide != -1) {
				length = strlen(result);
				result[length] = digits[priority];
				result[length+1] = '\0';
			}
			number=number%values[priority];
		}
	}
	/* Print the result! */
	printf("%s\n",result);
	free(result);
	return 0;
}
