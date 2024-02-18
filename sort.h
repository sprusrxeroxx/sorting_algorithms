#define SORT_H
#ifndef SORT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);

#endif/*SORT_H*/
