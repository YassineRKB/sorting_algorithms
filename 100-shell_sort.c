#include "sort.h"
/**
 * shell_sort - func to sort array using knuth sequance
 * @array: array to be sorted
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, k;
	int aux;

	if (!array || size < 2)
		return;
	for (k = 1; k < (size / 3); k = 3 * k + 1)
		;
	for(; k >= 1;)
	{
		for (i = k; i < size; i++)
			for (j = i; j >= k && array[j - k] > array[j];)
			{
				aux = array[j];
				array[j] = array[j - k];
				array[j - k] = aux;
				j -= k;
			}
		k /= 3;
		print_array(array, size);
	}
}
