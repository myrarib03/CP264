/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {
	// your code here
	int sum = 0, value;
	char input[STRING_SMALL];

	printf("Enter integers, one per line: \n");
	while (fgets(input, STRING_SMALL, stdin)) {
		if (sscanf(input, "%d", &value) != 1) {
			break;
		}
		sum += value;
	}
	return sum;
}
