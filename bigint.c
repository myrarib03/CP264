/**
 * -------------------------------------
 * @file  bigint.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-02-14
 *
 * -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
	BIGINT bn = { 0 };
	if (p == NULL)
		return bn;
	else if (!(*p >= '0' && *p <= '9')) { // not begin with digits
		return bn;
	} else if (*p == '0' && *(p + 1) == '\0') { // just "0"
		dll_insert_end(&bn, dll_node(*p - '0'));
		return bn;
	} else {
		while (*p) {
			if (*p >= '0' && *p <= '9') {
				dll_insert_end(&bn, dll_node(*p - '0'));
			} else {
				dll_clean(&bn);
				break;
			}
			p++;
		}
		return bn;
	}
}

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
// your code
	BIGINT sum = { 0 };
	NODE *p1 = op1.end, *p2 = op2.end;
	int carry = 0;

	while (p1 || p2 || carry) {
		int val1 = (p1) ? p1->data : 0;
		int val2 = (p2) ? p2->data : 0;
		int total = val1 + val2 + carry;

		carry = total / 10;
		dll_insert_start(&sum, dll_node(total % 10));

		if (p1)
			p1 = p1->prev;
		if (p2)
			p2 = p2->prev;
	}

	return sum;
}

BIGINT bigint_fibonacci(int n) {
// your code
	if (n == 0)
		return bigint("0");
	if (n == 1)
		return bigint("1");

	BIGINT a = bigint("0");
	BIGINT b = bigint("1");

	for (int i = 2; i <= n; i++) {
		BIGINT temp = bigint_add(a, b);
		dll_clean(&a);
		a = b;
		b = temp;
	}

	dll_clean(&a);
	return b;
}
