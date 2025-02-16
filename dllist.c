/**
 * -------------------------------------
 * @file  dllist.c
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
#include "dllist.h"

NODE* dll_node(char data) {
// your code
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	if (!new_node) {
		printf("Memory allocation failed!\n");
		return NULL;
	}
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

void dll_insert_start(DLL *dllp, NODE *np) {
// your code
	if (!dllp || !np)
		return;
	np->next = dllp->start;
	if (dllp->start)
		dllp->start->prev = np;
	else
		dllp->end = np;
	dllp->start = np;
	dllp->length++;
}

void dll_insert_end(DLL *dllp, NODE *np) {
// your code
	if (!dllp || !np)
		return;
	np->prev = dllp->end;
	if (dllp->end)
		dllp->end->next = np;
	else
		dllp->start = np;
	dllp->end = np;
	dllp->length++;
}

void dll_delete_start(DLL *dllp) {
// your code
	if (!dllp || !dllp->start)
		return;
	NODE *temp = dllp->start;
	dllp->start = dllp->start->next;
	if (dllp->start)
		dllp->start->prev = NULL;
	else
		dllp->end = NULL;
	free(temp);
	dllp->length--;
}
void dll_delete_end(DLL *dllp) {
// your code
	if (!dllp || !dllp->end)
		return;
	NODE *temp = dllp->end;
	dllp->end = dllp->end->prev;
	if (dllp->end)
		dllp->end->next = NULL;
	else
		dllp->start = NULL;
	free(temp);
	dllp->length--;
}

void dll_clean(DLL *dllp) {
// your code
	NODE *temp, *ptr = dllp->start;
	while (ptr) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	dllp->start = NULL;
	dllp->end = NULL;
	dllp->length = 0;
}
