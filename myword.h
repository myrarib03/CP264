/**
 * -------------------------------------
 * @file  myword.h
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-31
 *
 * -------------------------------------
 */
#ifndef MYWORD_H
#define MYWORD_H

#include <stdio.h>

#define WORD_LENGTH 20 // Maximum length of a word
#define MAX_LINE_LEN 1000 // Maximum length of a line
#define MAX_WORDS 1000

typedef enum {
	FALSE = 0, TRUE = 1
} BOOLEAN;

typedef struct {
	char word[WORD_LENGTH];
	int count;
} WORD;

typedef struct {
	int line_count;
	int word_count;
	int keyword_count;
} WORDSTATS;

/**
 * Load word data from a file and insert words into a dictionary.
 *
 * @param fp - file pointer to an opened text file
 * @param dictionary - char pointer to a char array where dictionary words are stored
 * @return - the number of words added into the dictionary
 */
int create_dictionary(FILE *fp, char *dictionary);

/**
 * Determine if a given word is contained in the dictionary.
 *
 * @param dictionary - char pointer to a char array of the dictionary
 * @param word - pointer to a given word
 * @return - TRUE if the word is in the dictionary, FALSE otherwise
 */
BOOLEAN contain_word(char *dictionary, char *word);

/**
 * Process text data from a file for word statistics.
 *
 * @param fp - FILE pointer of the input text data file
 * @param words - WORD array for keywords and their frequencies
 * @param dictionary - stop-word/common-word dictionary
 * @return - WORDSTATS value of processed word stats information
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif // MYWORD_H
