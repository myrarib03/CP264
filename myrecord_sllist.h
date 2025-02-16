/**
 * -------------------------------------
 * @file  myrecord_sllist.h
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-02-14
 *
 * -------------------------------------
 */

#ifndef SLL_H
#define SLL_H

typedef struct {
	char name[20];
	float score;
} RECORD;

typedef struct node {
	RECORD data;
	struct node *next;
} NODE;

typedef struct sllist {
	int length;
	NODE *start;
} SLL;

NODE* sll_search(SLL *sllp, char *name);
void sll_insert(SLL *sllp, char *name, float score);
int sll_delete(SLL *sllp, char *name);
void sll_clean(SLL *sllp);

#endif
