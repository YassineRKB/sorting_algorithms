#include "sort.h"
/**
 * heap_sort - func to sort array using heap sort algo
 * @array: array to be sorted
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i, aux;

	if (size <= 1)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapSift(array, size, size, (size_t)i);
	for (i = size - 1; i > 0; i--)
	{
		aux = array[i];
		array[i] = array[0];
		array[0] = aux;
		print_array(array, size);
		heapSift(array, size, (size_t)i, 0);
	}
}
/**
 * heapSift - recursive func to sift down array
 * @array: affected array
 * @start: start row index of the heap
 * @item: array item
 * @size: array size
*/
void heapSift(int *array, size_t size, size_t start, size_t item)
{
	size_t max = item, left = 2 * item + 1, right = 2 * item + 2;
	int aux;

	if (left < start && array[left] > array[max])
		max = left;
	if (right < start && array[right] > array[max])
		max = right;
	if (max != item)
	{
		aux = array[max];
		array[max] = array[item];
		array[item] = aux;
		print_array(array, size);
		heapSift(array, size, start, max);
	}
}

