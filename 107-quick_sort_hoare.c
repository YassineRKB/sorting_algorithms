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
	int pivot = array[end], aux;
	int i = start - 1, j = end + 1;

	while (1)
	{
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i >= j)
			break;
		aux = array[i];
		array[i] = array[j];
		array[j] = aux;
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
