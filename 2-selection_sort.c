#include "sort.h"
/**
 * selection_sort - func to sort array using selection algo
 * @array: array to be sorted
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, k;
	int aux;

	if (size < 2 || !array)
		return;
	while (i < size - 1)
	{
		k = i;
		j = i + 1;
		for (; j < size;)
		{
			if (array[j] < array[k])
				k = j;
			j++;
		}
		if (k != 1)
		{
			aux = array[k];
			array[k] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
		i++;
	}
}
