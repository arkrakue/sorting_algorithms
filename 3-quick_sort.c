#include "sort.h"

/**
 * quick_sort - Function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: array
 * @size: array's size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * partition - Partitioning the array using Lomuto partition scheme
 *
 * @array: array
 * @low: lower
 * @high: higher
 * @size: array's size
 *
 * Return: i
 */

int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = low;
	int pivot = array[high], aux = 0;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		aux = array[i + 1];
		array[i + 1] = array[high];
		array[high] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Function to sort an array with the
 * Quick sort algorithm
 *
 * @array: given array
 * @low: lower
 * @high:higher
 * @size: array's size
 *
 * Return: void
 */

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}
