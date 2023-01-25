#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 *	ascending order using the Bubble sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, state;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
        	state = 0;
		for (j = 0; j <= size - 2; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				state = 1;
			}
		}

		if (state == 0)
			return;
	}

}
