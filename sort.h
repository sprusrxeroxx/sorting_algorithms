#ifndef SORT_H
#define SORT_H

#include <stddef.h>

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/*UTILITIES*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

/*ALGOs*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);


#endif/*SORT_H*/
