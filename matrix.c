/**
 * -------------------------------------
 * @file  matrix.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-24
 *
 * -------------------------------------
 */

#include "matrix.h"

//norm needs to be reviewed
float norm(float *v, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i] * v[i];
	}
	return sqrt(sum);
}

float dot_product(float *v1, float *v2, int n) {
	float result = 0;
	for (int i = 0; i < n; i++) {
		result += v1[i] * v2[i];
	}
	return result;
}

void matrix_multiply_vector(float *m, float *v, float *vout, int n) {
	for (int i = 0; i < n; i++) {
		vout[i] = 0;
		for (int j = 0; j < n; j++) {
			vout[i] += m[i * n + j] * v[j];
		}
	}
}

void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m3[i * n + j] = 0;
			for (int k = 0; k < n; k++) {
				m3[i * n + j] += m1[i * n + k] * m2[k * n + j];
			}
		}
	}
}
