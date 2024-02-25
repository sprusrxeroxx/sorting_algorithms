#include "sort.h"
#include<stdio.h>

/**
 *shell_sort - a function that sorts an array of int using the
 *Shell sort algorithm and the Knuth sequence
 *
 *@array: an integer array
 *@size: the size of the array
 *
 *Description: Arranges an int array in ascending order using shell sort
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, n, gap;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (n = 1; n < size; n = n * 3 + 1)
		gap = n;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}
	print_array(array, size);
	}
}
