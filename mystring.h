/**
 * -------------------------------------
 * @file  mystring.h
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-31
 *
 * -------------------------------------
 */
/*
 * your program signature
 */

#ifndef MYSTRING_H
#define MYSTRING_H

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a string
 * @return - return the number of words.
 */
int str_words(char *s);

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.
 */
int str_lower(char *s);

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s);

#endif
