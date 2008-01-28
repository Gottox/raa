/* Copyright (C) Enno Boland
 *
 * This file is released under the GPLv2.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int main (int argc, char **argv)
{
	/* Usage */
	if(argc < 2 || strcmp(argv[1],"-h") == 0) {
		printf("usage: %s roman_numerals\n",argv[0]);
		exit(1);
	}
	
	/* Digits and their decimal values */
	char digits[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'  };
	int values[7]  = {  1,   5,   10,  50, 100, 500, 1000 };

	/* As we need argv[1] later (and of course it would be ugly), we use str as our data source to the converter. */
	char *str = argv[1];
	
	/* Our result variable */
	int decimal = 0;
	
	/* We've got 7 different roman digits. This is our counter. */
	int priority = 7;
	/* This is also a counter. It will be used for subtractive notations. */
	int sub_priority;

	/* Starting our converter. Beginning with the digit with the highest priority. (Must be the digit with the highest value) */
	while (--priority != -1) {

		while(strchr(str, digits[priority]) != NULL) {
			/* While we find some digit, we forget everything which comes before. */
			str = strchr(str, digits[priority]);
			
			/* We are adding the value of the digit to the result. */
			decimal += values[priority];

			/* If it is not the first digit of the number, test if it could be a subtractive notation */
			if(str != argv[1]) {

				/* Setting a counter. This is not 7 like the main counter, because
				 * only smaller digits as the "main digit" can be used for subtractive
				 * notation. */
				sub_priority = priority;

				/* Searching for the right digit. */
				while(--sub_priority != -1) {
					/* If the right digit is found, substract it from the result. */
					if(digits[sub_priority] == str[-1])
						decimal -= values[sub_priority];
				}
			}
			/* This is very important, because without it the program would produce an endless loop. */
			str++;
		}
	}
	/* Finally print out the value. */
	printf("%i\n",decimal);
	return 0;
}
