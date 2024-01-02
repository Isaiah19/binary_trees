#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of
 * integers
 *
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to a newly allocated array containing the sorted values, or
 * NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	arr = calloc(1, sizeof(int));
	if (!arr)
		return (NULL);

	while (heap)
	{
		arr = realloc(arr, sizeof(int) * (*size + 1));
		arr[*size] = heap_extract(&heap);
		*size += 1;
	}
	return (arr);
}
