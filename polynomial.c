/**
 * -------------------------------------
 * @file  polynomial.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-24
 *
 * -------------------------------------
 */

#include "polynomial.h"

float horner(float *p, int n, float x) {
	float result = p[0];
	for (int i = 1; i < n; i++) {
		result = result * x + p[i];
	}
	return result;
}

void derivative(float *p, float *d, int n) {
	if (n <= 1) {
		d[0] = 0; // Derivative of a constant is 0
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		d[i] = p[i] * (n - 1 - i);
	}
}

float newton(float *p, int n, float x0) {
	float tolerance = 1e-6;
	int max_iterations = 100;

	float *d = (float*) malloc((n - 1) * sizeof(float));
	derivative(p, d, n);

	for (int i = 0; i < max_iterations; i++) {
		float fx = horner(p, n, x0);
		float f_prime_x = horner(d, n - 1, x0);

		if (fabs(f_prime_x) < tolerance) {
			printf("Derivative is too small. Stopping iterations.\n");
			free(d);
			return x0;
		}

		float x1 = x0 - fx / f_prime_x;

		if (fabs(x1 - x0) < tolerance) {
			free(d);
			return x1;
		}

		x0 = x1;
	}

	printf("Maximum iterations reached. Returning last approximation.\n");
	free(d);
	return x0;
}
