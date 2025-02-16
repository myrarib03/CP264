/**
 * -------------------------------------
 * @file  myword.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-31
 *
 * -------------------------------------
 */
#include "myword.h"
#include "mystring.h"
#include <string.h>

int create_dictionary(FILE *fp, char *dictionary) {
	int count = 0;
	char word[WORD_LENGTH];
	dictionary[0] = '\0'; // Initialize dictionary as an empty string

	while (fscanf(fp, "%19s", word) != EOF) { // Read words from the file
		str_lower(word); // Convert word to lowercase
		str_trim(word); // Remove unnecessary spaces
		if (strlen(dictionary) + strlen(word) + 1 < MAX_LINE_LEN) { // Prevent overflow
			strcat(dictionary, word);
			strcat(dictionary, " ");
			count++;
		}
	}
	return count;
}

BOOLEAN contain_word(char *dictionary, char *word) {
	char temp[MAX_LINE_LEN];
	snprintf(temp, sizeof(temp), " %s ", word); // Add spaces to ensure whole word match
	return (strstr(dictionary, temp) != NULL) ? TRUE : FALSE;
}

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
	WORDSTATS stats = { 0, 0, 0 };
	char line[MAX_LINE_LEN], word[WORD_LENGTH];

	while (fgets(line, sizeof(line), fp)) {
		stats.line_count++;
		char *token = strtok(line, " ,.!?\n");
		while (token) {
			stats.word_count++;
			str_lower(token);
			str_trim(token);

			if (!contain_word(dictionary, token)) {
				int found = 0;
				for (int i = 0; i < stats.keyword_count; i++) {
					if (strcmp(words[i].word, token) == 0) {
						words[i].count++;
						found = 1;
						break;
					}
				}
				if (!found && stats.keyword_count < MAX_WORDS) {
					strncpy(words[stats.keyword_count].word, token,
					WORD_LENGTH - 1);
					words[stats.keyword_count].word[WORD_LENGTH - 1] = '\0'; // Ensure null termination
					words[stats.keyword_count].count = 1;
					stats.keyword_count++;
				}
			}
			token = strtok(NULL, " ,.!?\n");
		}
	}
	return stats;
}
