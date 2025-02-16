/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Myra ribeiro 169030590
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long,
		int length) {
	// your code here
	if (data == NULL || fp_short == NULL || fp_long == NULL) {
		return;
	}
	for (int m = 0; m < data->lines; m++) {
		if ((int) strlen(data->strings[m]) < length) {
			fprintf(fp_short, "%s\n", data->strings[m]);
		} else {
			fprintf(fp_long, "%s\n", data->strings[m]);
		}
	}
}
