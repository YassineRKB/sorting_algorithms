#include "sort.h"

/**
 * merge - merges the parts
 * @array: array to be sorted
 * @start: lower bound
 * @n: number of elements
 * @vector: direction on the merging
 */
void merge(int *array, int start, int n, int vector)
{
	int center = n / 2, i = start, aux;

	if (n <= 1)
		return;
	while (i < start + center)
	{
		if (vector == (array[i] > array[i + center]))
		{
			aux = array[i];
			array[i] = array[i + center];
			array[i + center] = aux;
		}
		i++;
	}
	merge(array, start, center, vector);
	merge(array, start + center, center, vector);
}
/**
 * rearrange - func to split and sorts array
 * @array: array to be sorted
 * @start: start index
 * @n: number of items
 * @size: size of the array
 * @vector: direction of merging
 */
void rearrange(int *array, int start, int n, int vector, size_t size)
{
	int center = n / 2;
	char *direction;

	if (n <= 1)
		return;

	if (vector > 0)
		direction = "UP";
	else
		direction = "DOWN";
	printf("Merging [%d/%ld] (%s):", n, size, direction);
	printf("\n");
	print_array(&array[start], n);
	rearrange(array, start, center, 1, size);
	rearrange(array, start + center, center, 0, size);
	merge(array, start, n, vector);
	printf("Result [%d/%ld] (%s):", n, size, direction);
	printf("\n");
	print_array(&array[start], n);
}
/**
 * bitonic_sort - func to sort array using bitonic sort algo
 * @array: array to be sorted
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	rearrange(array, 0, size, 1, size);
}
