#include "sort.h"
/**
 * quick_sort - func to sort array using quick sort algo
 * @array: array to be sorted
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	rec_sort(array, size, 0, size - 1);
}
/**
 * rec_sort - recursive function to implement quicksort
 * @array: array to be sorted
 * @size: size of array
 * @start: starting index of array
 * @end: ending index of array
*/
void rec_sort(int *array, size_t size, int start, int end)
{
	int partitionIndex;

	if (start < end)
	{
		partitionIndex = partition(array, size, start, end);
		rec_sort(array, size, start, partitionIndex - 1);
		rec_sort(array, size, partitionIndex + 1, end);
	}
}
/**
 * partition - function to partition the array using lumto algo
 * @array: array to be partitioned
 * @size: size of the array
 * @start: starting index
 * @end: ending index
*/
int partition(int *array, size_t size, int start, int end)
{
	int i = start, j = start, aux, *piv;

	if (size == 0 || start < 0 || end >= (int) size || (int) start >= end)
        return -1;

	piv = &array[end];
	while (j <= end)
	{
		if (array[j] < *piv)
		{
			if (i < j)
			{
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
				print_array(array, size);
			}
			i++;
		}
		j++;
	}
	if (array[i] > *piv)
	{
		aux = array[i];
		array[i] = *piv;
		array[end] = aux;
		print_array(array, size);
	}
	return (i);
}
