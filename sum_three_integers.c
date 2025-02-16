/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {

	// your code here
	int num1, num2, num3;
	char input[STRING_SMALL];

	while (1) {
		printf("Enter three comma-separated integers: ");
		if (fgets(input, STRING_SMALL, stdin)) {
			if (sscanf(input, "%d,%d,%d", &num1, &num2, &num3) == 3) {
				return num1 + num2 + num3;
			}
		}
		printf("The integers were not properly entered.\n");
	}
}
