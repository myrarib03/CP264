/**
 * -------------------------------------
 * @file  myrecord_sllist.c
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
#include <string.h>
#include "myrecord_sllist.h"

NODE* sll_search(SLL *sllp, char *name) {
// your code
	NODE *current = sllp->start;
	while (current != NULL) {
		if (strcmp(current->data.name, name) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

void sll_insert(SLL *sllp, char *name, float score) {
// your code
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	if (new_node == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	strcpy(new_node->data.name, name);
	new_node->data.score = score;
	new_node->next = sllp->start;
	sllp->start = new_node;
	sllp->length++;

}

int sll_delete(SLL *sllp, char *name) {
// your code
	NODE *current = sllp->start, *prev = NULL;

	while (current != NULL && strcmp(current->data.name, name) != 0) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		return 0; // Not found
	}

	if (prev == NULL) {
		sllp->start = current->next;
	} else {
		prev->next = current->next;
	}

	free(current);
	sllp->length--;
	return 1; // Success
}

void sll_clean(SLL *sllp) {
	NODE *temp, *ptr = sllp->start;
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	sllp->start = NULL;
	sllp->length = 0;
}

