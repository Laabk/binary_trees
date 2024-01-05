#include "binary_trees.h"

/**
 * array_to_heap - this creates a Max Binary Heap tree from an array
 * @array: the array to be converted
 * @size: the array size
 * Return: pointer to created node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int d;
	heap_t *root = NULL;

	while (d < size)
	{
	heap_insert(&root, array[d]);
	d++;
	}
	return (root);
}
