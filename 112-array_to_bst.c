#include "binary_trees.h"

/**
 * array_to_bst - makes a Binary Search Tree from an array
 * @array: the pointer to first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int a = 0;
	bst_t *root = NULL;

	while (a < size)
	{
	bst_insert(&root, array[a]);
	a++;
	}

	return (root);
}
