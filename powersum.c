/**
 * -------------------------------------
 * @file  powersum.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-17
 *
 * -------------------------------------
 */
#include "powersum.h"

int power_overflow(int b, int n) {
	if (b <= 0 || n < 0) {
		return 1;
	}

	int result = 1;
	for (int i = 0; i < n; ++i) {
		int previous = result;
		result *= b;
		if (result / b != previous) {
			return 1;
		}
	}

	return 0;
}

// Function to compute b to the power of n
int mypower(int b, int n) {
	if (b <= 0 || n < 0) {
		return 0;
	}

	int results = 1;
	for (int i = 0; i < n; ++i) {
		int previous = results;
		results *= b;
		if (results / b != previous) {
			return 0;
		}
	}

	return results;
}

// Function to compute the sum of powers from b^0 to b^n
int powersum(int b, int n) {
	if (b <= 0 || n < 0) {
		return 0;
	}

	int sum = 0;
	int current_power = 1;

	for (int i = 0; i <= n; ++i) {
		int previous_sum = sum;
		sum += current_power;
		if (sum < previous_sum) {
			return 0;
		}

		int previous = current_power;
		if (i < n) {
			current_power *= b;
			if (current_power / b != previous) {
				return 0;
			}
		}
	}

	return sum;
}
