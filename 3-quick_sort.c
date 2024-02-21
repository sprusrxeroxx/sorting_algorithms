#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b);
void lomuto_sort(int *array, size_t size, int low, int high);
int partition(int *array, size_t size, int low, int high);

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;

	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		lomuto_sort(array, size, low, pi - 1);
		lomuto_sort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
