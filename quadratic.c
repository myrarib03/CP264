/**
 * -------------------------------------
 * @file  quadratic.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-17
 *
 * -------------------------------------
 */

#include "quadratic.h"
#include <math.h>
#define EPSILON 1e-6

int solution_type(float a, float b, float c) {
	int t = -1;
	if (fabs(a) < EPSILON)
		t = 0;
	else {

// your code
		float discriminant = b * b - 4 * a * c;
		if (discriminant > EPSILON)
			t = 2;
		else if (fabs(discriminant) < EPSILON)
			t = 1;
		else
			t = -1;
	}
	return t;
}

float real_root_big(float a, float b, float c)
// call solution_type to determine solution type, procede if the equation has real solutions.
{
	if (solution_type(a, b, c) > 0) {
		float discriminant = b * b - 4 * a * c;
		return (-b + sqrt(discriminant)) / (2 * a);
	}
	return 0;
}

float real_root_small(float a, float b, float c) {
// your code

	if (solution_type(a, b, c) > 0) {
		float discriminant = b * b - 4 * a * c;
		return (-b - sqrt(discriminant)) / (2 * a);
	}
	return 0;
}
