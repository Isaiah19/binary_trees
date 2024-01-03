#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
