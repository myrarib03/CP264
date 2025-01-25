/**
 * -------------------------------------
 * @file  mychar.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-17
 *
 * -------------------------------------
 */
#include "mychar.h"

int mytype(char c) {
	int r = -1;
	if (c >= '0' && c <= '9') {
		r = 0;
	} else if (c == '+' || c == '-' || c == '*' || c == '/') {
		r = 1;
	} else if (c == '(') {
		r = 2;
	} else if (c == ')') {
		r = 3;
	} else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
		r = 4;
	} else {
		r = -1;
	}
	return r;
}

char case_flip(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 'A';
	} else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	} else {
		return c;
	}
}

int digit_to_int(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else {
		return -1;
	}
}

