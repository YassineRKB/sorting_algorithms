#include "sort.h"
/**
 * selection_sort - func to sort array using selection algo
 * @array: array to be sorted
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0, l;
	int k;

	if (size <= 1)
		return;
	while (j < size - 1)
	{
		k = array[j];
		l = j;
		i = j;
		while (i < size)
		{
			if (k > array[i])
			{
				k = array[i];
				l = i;
			}
			i++;
		}
		if (array[j] != array[l])
		{
			array[l] = array[j];
			array[j] = k;
			print_array(array, size);
		}
		j++;
	}
}
