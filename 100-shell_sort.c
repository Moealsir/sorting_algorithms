#include <stddef.h>
#include <stdio.h>

void print_array(const int *array, size_t size);

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		print_array(array, size);

		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/* Reduce the gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}

}
