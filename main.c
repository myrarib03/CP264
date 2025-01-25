/**
 * -------------------------------------
 * @file  main.c
 * Lab 1 Main Source Code File
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include "parameters.h"

/**
 * Test the various parameter handling functions.
 *
 * @param argc - size of argv
 * @param argv - array of strings passed on command line
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);
	parameters(argc, argv);
	return EXIT_SUCCESS;
}
