#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: array input to be sorted
 * @size: size of array
 *
 * Return: Always Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, min_i;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_i = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_i])
			{
				min_i = j;
			}
		}

		if (min_i != i)
		{
			tmp = array[min_i];
			array[min_i] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}

	}
}
