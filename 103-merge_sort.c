#include "sort.h"
/**
 * merge_sort - func to sort array using merger sort algo
 * @array: array to be sorted
 * @size: size of array to be sorted
*/
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	splice(array, 0, size - 1);
}
/**
 * splice - func to split array recursively
 * @array: array to be split
 * @start: start index
 * @end: end index
*/
void splice(int *array, int start, int end)
{
	int center;

	if (start >= end)
		return;
	center = start + (end - start) / 2;
	if (center - start >= end - center)
	{
		center--;
	}
	splice(array, start, center);
	splice(array, center + 1, end);
	merge(array, start, center, end);
}
/**
 * merge - func to merge sub arrays
 * @array: affected array
 * @start: start index
 * @center: center index
 * @end: end index
*/
void merge(int *array, int start, int center, int end)
{
	int i, j, k, n, *left, *right, *subarr;
	int l_size = center - start + 1;
	int r_size = end - center;

	subarr = malloc(sizeof(int) * (end - start + 1));
	right = subarr + l_size;
	left = subarr;
	switcher(array, right, left, r_size, l_size, start, center);
	for (i = 0, j = 0, k = start; i < l_size && j < r_size; k++)
	{
		if (left[i] <= right[j])
			array[k] = left[i++];
		else
			array[k] = right[j++];
	}
	while (i < l_size)
		array[k++] = left[i++];
	while (j < r_size)
		array[k++] = right[j++];
	printf("[Done]: ");
	for (i = start; i < k; i++)
	{
		n = array[i];
		printf("%d", n);
		if (i < k - 1)
			printf(", ");
		else
			printf("\n");
	}
	free(subarr);
}
/**
 * switcher - moves array contents to left and right subarrays
 * @array: affected array
 * @left: left array
 * @right: right array
 * @l_size: size of left array
 * @r_size: size of right array
 * @start: start index
 * @center: center index
 */
void switcher(int *array, int *right, int *left, int r_size,
	int l_size, int start, int center)
{
	int i;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < l_size; i++)
	{
		left[i] = array[start + i];
		printf("%d", left[i]);
		if (i < l_size - 1)
			printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (i = 0; i < r_size; i++)
	{
		right[i] = array[center + 1 + i];
		printf("%d", right[i]);
		if (i < r_size - 1)
			printf(", ");
	}
	printf("\n");
}
