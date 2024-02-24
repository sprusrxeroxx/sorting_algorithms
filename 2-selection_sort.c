#include "sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: an unsorted array of integers
 * @size: The size of the array
 * Description: Returns a sorted array of ints
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, min_index;
  /* Base case: empty or single-element array */
	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
				
		}
		if (i != min_index)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
