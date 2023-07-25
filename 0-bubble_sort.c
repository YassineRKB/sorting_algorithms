#include "sort.h"
/**
 * bubble_sort - func to sort array using bubble algo
 * @array: array to be sorted
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t j, i = 0;
	int aux;

	if (size <= 1)
		return;
	for (; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j + 1];
				array[j + 1] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
}
