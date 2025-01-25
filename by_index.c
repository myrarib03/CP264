/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "by_index.h"

void fill_values_by_index(int values[], int size) {
	//uses array indexing to create an array "values" and populate it with integers
	//that increase consecutively
	for (int i = 0; i < size; i++) {
		values[i] = i + 1;
	}
}

void fill_squares_by_index(int values[], long int squares[], int size) {
	// populates squares with the integers in values using array indexing
	for (int i = 0; i < size; i++) {
		squares[i] = (values[i] * values[i]);
	}
}

void print_by_index(int values[], long int squares[], int size) {
	//prints the elements in values and squares in two columns with array indexing
	printf("Value  Square\n");
	printf("-----  ----------\n");
	for (int i = 0; i < size; i++) {
		printf("%-5d  %-10d\n", values[i], squares[i]);
	}
}
