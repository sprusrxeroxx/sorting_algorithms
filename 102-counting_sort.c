#include "sort.h"
#include<stdio.h>

/**
 *
 *
 *
 *
 */

void counting_sort(int *array, size_t size)
{
	int count_array[], sorted_array[], max = array[0];
	size_t i;

	/**Find Maximum */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (int i = 1; i <= max; i++)
	       count_array[i] += count_array[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
}

	
