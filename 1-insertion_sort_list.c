#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - A function that sorts a list using insertion sort
 * @list: List of integers 
 * Returns: A sorted list of integers 
 */

void insertion_sort_list(listint_t **list) {
    listint_t *sorted_list = NULL;
    listint_t *current = *list;

	while (current != NULL) {
		listint_t *next = current->next;

		/* Remove current node from original list */
		if (current->prev != NULL) 
			current->prev->next = current->next;

		if (current->next != NULL)
			current->next->prev = current->prev;

        	/* Insert node in sorted list */
        	insert_node(&sorted_list, current);

		current = next;
		print_list(sorted_list);
	}
		/* Update head of original list */
		*list = sorted_list;
}
