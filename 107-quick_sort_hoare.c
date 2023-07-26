#include "sort.h"
/**
 * partition - function to partition the array using lumto algo
 * @array: array to be partitioned
 * @size: size of the array
 * @start: starting index
 * @end: ending index
 * Return: value int
*/
int partition(int *array, size_t size, int start, int end)
{
	int i = start, j = start, aux, *piv;

	if (size == 0 || start < 0 || end >= (int) size || (int) start >= end)
		return (-1);

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
/**
 * splicer - recusrsive function to split array
 * @array: array to be sorted
 * @start: start index
 * @end: end index
 * @size: size of array
 */
void splicer(int *array, int start, int end, size_t size)
{
	int partitionInedx;

	if (start < end)
	{
		partitionInedx = partition(array, size, start, end);
		splicer(array, start, partitionInedx - 1, size);
		splicer(array, partitionInedx, end, size);
	}
}
/**
 * quick_sort_hoare - func to sort array using
 * quick sort hoare algo
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	splicer(array, 0, size - 1, size);
}
