#include "sort.h"
/**
 * radix_sort - func to sort array using radix algo
 * @array: array to sort
 * @size: size of array
*/
void radix_sort(int array[], size_t size)
{
	int max = 0;
	int j = 1, *ptr, *out;
	size_t i = 1;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (max < array[i])
			max = array[i];
	while (max / j > 0)
	{
		out = malloc(sizeof(int) * size);
		ptr = malloc(sizeof(int) * 10);
		if (!out || !ptr)
			return;
		for (i = 0; i < 10; i++)
			ptr[i] = 0;
		for (i = 0; i < size; i++)
			ptr[(array[i] / j) % 10]++;
		for (i = 1; i < 10; i++)
			ptr[i] += ptr[i - 1];
		for (i = size - 1;; i--)
		{
			out[ptr[(array[i] / j) % 10] - 1] = array[i];
			ptr[(array[i] / j) % 10]--;
			if (i == 0)
				break;
		}
		for (i = 0; i < size; i++)
			array[i] = out[i];
		free(ptr), free(out);
		print_array(array, size);
		j *= 10;
	}
}
