/**
 * -------------------------------------
 * @file  mysort.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-02-07
 *
 * -------------------------------------
 */

#include "mysort.h"

// swap pointers
void swap(void **x, void **y) {
	void *temp = *y;
	*y = *x;
	*x = temp;
}

// a compare floating values pointed by void pointers.
int cmp(void *x, void *y) {
	float a = *(float*) x;
	float b = *(float*) y;
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

void select_sort(void *a[], int left, int right) {
// your code
	for (int i = left; i < right; i++) {
		int min_index = i;
		for (int j = i + 1; j <= right; j++) {
			if (cmp(a[j], a[min_index]) < 0) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(&a[i], &a[min_index]);
		}
	}
}

void quick_sort(void *a[], int left, int right) {
// your code
	if (left >= right)
		return;

	void *pivot = a[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (cmp(a[j], pivot) < 0) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[right]);

	quick_sort(a, left, i);
	quick_sort(a, i + 2, right);
}

void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*)) {
// your code
	if ((right - left) <= 10) {  // Use selection sort for small subarrays
		for (int i = left; i < right; i++) {
			int min_index = i;
			for (int j = i + 1; j <= right; j++) {
				if (cmp(a[j], a[min_index]) < 0) {
					min_index = j;
				}
			}
			if (min_index != i) {
				swap(&a[i], &a[min_index]);
			}
		}
	} else {  // Use quicksort for larger subarrays
		if (left >= right)
			return;

		void *pivot = a[right];
		int i = left - 1;
		for (int j = left; j < right; j++) {
			if (cmp(a[j], pivot) < 0) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i + 1], &a[right]);

		my_sort(a, left, i, cmp);
		my_sort(a, i + 2, right, cmp);
	}
}

