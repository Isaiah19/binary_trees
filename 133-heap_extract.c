#include <stdlib.h>
#include "binary_trees.h"

size_t get_node_count(const heap_t *tree);
heap_t *get_last_node(heap_t *root, size_t index, size_t size);
void top_down_heapify(heap_t *root);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last = NULL;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = get_node_count(*root);
	last = get_last_node(*root, 0, size);

	(*root)->n = last->n;

	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}
	else
		*root = NULL;
	free(last);
	top_down_heapify(*root);
	return (value);
}

/**
 * get_node_count - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes in the tree
 */
size_t get_node_count(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_node_count(tree->left) + get_node_count(tree->right));
}

/**
 * get_last_node - Gets the last node of a Max Binary Heap
 *
 * @root: Pointer to the root node of the Heap
 * @index: Index of the current node in the binary representation of the size
 * @size: Size of the Heap
 *
 * Return: Pointer to the last node of the Heap
 */
heap_t *get_last_node(heap_t *root, size_t index, size_t size)
{
	heap_t *node = root;

	if (!root || index >= size)
		return (NULL);
	if (index == size - 1)
		return (node);
	node = get_last_node(root->left, 2 * index + 1, size);
	if (node)
		return (node);
	return (get_last_node(root->right, 2 * index + 2, size));
}

/**
 * top_down_heapify - Moves the node at the top of the tree down to its
 * correct position in the Max Binary Heap
 *
 * Description: This function compares the value of the current node with the
 * values of its left and right children. If the value of the current node is
 * less than the value of either of its children, the values of the current
 * node and the child node with the largest value are swapped. This process
 * is repeated until the current node is greater than both of its children.
 *
 * @root: Pointer to the root node of the Heap
 * Return: Nothing
 */
void top_down_heapify(heap_t *root)
{
	heap_t *largest = root, *current = NULL;
	int temp;

	while (largest != current)
	{
		current = largest;
		if (current->left && current->left->n > current->n)
			largest = current->left;
		if (current->right && current->right->n > largest->n)
			largest = current->right;
		temp = current->n;
		current->n = largest->n;
		largest->n = temp;
	}
}
