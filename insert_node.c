#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node - a function that inserts a node in the middle or start of a doubly linked list
 * @head: The first node of a doubly linked list
 * @new_node: The node to be replaced 
 * Returns: void
 */

void insert_node(listint_t **head, listint_t *new_node) {
	listint_t *current = *head;
	listint_t *prev = NULL;

	while (current != NULL && current->n < new_node->n) {
		prev = current;
		current = current->next;
	}

	if (prev == NULL) {
	/* Insert at the beginning */
		new_node->next = *head;
		if (*head != NULL) 
			(*head)->prev = new_node;
		*head = new_node;
	} 
	else {
	/* Insert in the middle */
		prev->next = new_node;
		new_node->prev = prev;
		new_node->next = current;
		if (current != NULL)
			current->prev = new_node;
	}
}
