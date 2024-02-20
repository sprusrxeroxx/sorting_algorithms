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
	int tmp;
	listint_t *temp_prev;
	listint_t *temp_next;

	if (*list == NULL)
		return;

	while (curr != NULL) {
		if (curr->next != NULL && curr->next->n < curr->n){
			tmp = curr->n;
			curr->n = curr->next->n;
			curr->next->n = tmp;

			temp_prev = curr->prev;
			temp_next = curr->next;
			if (temp_prev != NULL){
				temp_prev->next = curr->next;
			}
			else{
				*list = curr->next;
			}
			curr->next->prev = temp_prev;
			curr->next->next = curr;
			curr->prev = curr->next;
			curr->next = temp_next;
			
			if (temp_next != NULL){
                                temp_next->prev = curr;
                        }
		}
		print_list(*list);
                curr = curr->next;
	}
	printf("\n");
}
