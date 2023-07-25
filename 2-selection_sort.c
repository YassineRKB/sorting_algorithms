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
		j = i;
		for (k = i + 1; k < size;)
		{
			if (array[k] < array[j])
				j = k;
			k++;
		}
		if (j != 1)
		{
			aux = array[j];
			array[j] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
		i++;
	}
}
