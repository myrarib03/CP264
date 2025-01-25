/**
 * -------------------------------------
 * @file  fibonacci.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-24
 *
 * -------------------------------------
 */
#include "fibonacci.h"

int iterative_fibonacci(int n) {
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int a = 0, b = 1, temp;
	for (int i = 2; i <= n; i++) {
		temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}

int recursive_fibonacci(int n) {
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int dpbu_fibonacci(int *f, int n) {
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int dptd_fibonacci(int *f, int n) {
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (f[n] != -1)
		return f[n];

	f[n] = dptd_fibonacci(f, n - 1) + dptd_fibonacci(f, n - 2);
	return f[n];
}
