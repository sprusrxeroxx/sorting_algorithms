#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - A function that sorts a list using insertion sort
 * @list: List of integers
 * Returns: A sorted list of integers
 */


/* function to sort a doubly linked list using insertion sort */
void insertion_sort_list(listint_t **list) {

	listint_t *curr = *list;
	listint_t *temp = curr->next;

	if (*list == NULL)
		return;

	while (curr != NULL) {
		if (curr->next != NULL && curr->next->n < curr->n){
			temp = curr->next;

			curr->next = temp->next;

			if (temp->next != NULL){
				temp->next->prev = curr;
			}
			temp->prev = curr->prev;

			if (curr->prev != NULL){
                                curr->prev->next = temp;
                        }
			else{
				*list = temp;
			}
			temp->next = curr;
			curr->prev = temp;
		}
		print_list(*list);
                curr = curr->next;
	}
	printf("\n");
}
