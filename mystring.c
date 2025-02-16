/**
 * -------------------------------------
 * @file  mystring.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-31
 *
 * -------------------------------------
 */

#include "mystring.h"

/**
 *  add your comment
 */
int str_words(char *s) {
// your code
	int count = 0;
	int in_word = 0;
	while (*s) {
		if (isalpha(*s)) {
			if (!in_word) {
				count++;
				in_word = 1;
			}
		} else if (*s == ' ' || *s == '\t' || *s == ',' || *s == '.') {
			in_word = 0;
		}
		s++;
	}
	return count;
}
/**
 *  add your comment
 */
int str_lower(char *s) {
// your code
	int count = 0;
	while (*s) {
		if (isupper(*s)) {
			*s = tolower(*s);
			count++;
		}
		s++;
	}
	return count;
}

/**
 *  add your comment
 */
void str_trim(char *s) {
// your code
	char *dst = s;
	int space = 0;
	while (*s) {
		if (*s != ' ' || (space == 0)) {
			*dst++ = *s;
		}
		space = (*s == ' ');
		s++;
	}
	*dst = '\0';
}
