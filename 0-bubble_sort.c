#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * bubble_sort- bubble sort algorithm that takes an int array and sorts it in ascending order
 * @array - an integer array 
 * @size - the size of an array 
 * Returns:  a sorted list of integers 
 */


void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, tmp;

	for (i = 0; i < size - 1; i++) 
		{
        /*Flag to indicate if any swaps occurred in this pass*/
			bool swapped = false;

			for (j = 0; j < size - i - 1; j++) 
			{
				if (array[j] > array[j + 1]) 
				{
					tmp = array[j + 1];
					array[j + 1] = array[j];
					array[j] = tmp;
					swapped = true;
					print_array(array, size);
				}
			}

	/*If no swaps occurred in this pass, the array is already sorted*/
			if (!swapped)
			break;
		}
}
