/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
	// Allocate memory to the data structure
	name_set *set = malloc(sizeof *set);
	// Initialize the header fields.
	set->front = NULL;
	set->rear = NULL;
	return set;
}

int name_set_free(name_set **set) {
	if (!set || !*set)
		return 0; // Check if set is valid

	int count = 0;
	name_set_node *current = (*set)->front;
	while (current) {
		name_set_node *temp = current;
		current = current->next;
		free(temp); // Free each node
		count++;
	}

	free(*set); // Free the header structure
	*set = NULL;
	return count + 1; // Including the header node
}

BOOLEAN name_set_append(name_set *set, const char *first_name,
		const char *last_name) {
	if (!set || !first_name || !last_name)
		return FALSE;
	if (name_set_contains(set, first_name, last_name))
		return FALSE; // Ensure uniqueness

	// Create a new node
	name_set_node *new_node = malloc(sizeof *new_node);
	if (!new_node)
		return FALSE; // Allocation failure

	// Copy names into the node
	strncpy(new_node->first_name, first_name, NAME_LEN - 1);
	new_node->first_name[NAME_LEN - 1] = '\0';
	strncpy(new_node->last_name, last_name, NAME_LEN - 1);
	new_node->last_name[NAME_LEN - 1] = '\0';
	new_node->next = NULL;

	// Insert the new node
	if (!set->front) {
		set->front = set->rear = new_node;
	} else {
		set->rear->next = new_node;
		set->rear = new_node;
	}

	return TRUE;
}
BOOLEAN name_set_contains(const name_set *set, const char *first_name,
		const char *last_name) {
	if (!set || !first_name || !last_name)
		return FALSE;

	name_set_node *current = set->front;
	while (current) {
		if (strcmp(current->first_name, first_name) == 0
				&& strcmp(current->last_name, last_name) == 0) {
			return TRUE; // Name found
		}
		current = current->next;
	}
	return FALSE; // Name not found
}

void name_set_print(const name_set *set) {
	if (!set)
		return;

	name_set_node *current = set->front;
	while (current) {
		printf("%s, %s\n", current->last_name, current->first_name);
		current = current->next;
	}
}

