#include "sort.h"
/**
 * counting_sort - func that sorts an array using the counting sort algo
 * @array: array to be sorted
 * @size: size of the array to be sorted
*/
void counting_sort(int *array, size_t size)
{
	int m, *ptr, *out;
	size_t i, j, k;

	if (!array || size < 2)
		return;

	m = array[0];
	i = 1;
	while (i < size)
	{
		if (m < array[i])
			m = array[i];
		i++;
	}
	ptr = malloc(sizeof(int) * (m + 1));
	for (i = 0; i < size; i++)
		ptr[array[i]]++;
	j = (size_t)m;
	for (i = 1; i <= j; i++)
		ptr[i] = ptr[i] + ptr[i - 1];
	k = (size_t)(m + 1);
	print_array(ptr, k);
	out = malloc(sizeof(int) * size);
	i = size;
	while (i > 0)
	{
		i--;
		ptr[array[i]]--;
		out[ptr[array[i]]] = array[i];
	}
	free(ptr);
	i = 0;
	while (i < size)
	{
		array[i] = out[i];
		i++;
	}
	free(out);
}
