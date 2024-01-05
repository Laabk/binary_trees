#include "binary_trees.h"

/**
 * ax_sort - this func create the tree using the half element
 * of the array
 * @parent: the parent of the node to create
 * @array: array that has sorted
 * @begin: location of array starts
 * @last: location of array ends
 * Return: tree created
 */

avl_t *ax_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	int middl = 0;
	binary_tree_t *a;

	if (begin <= last)
	{
		middl = (begin + last) / 2;
		a = binary_tree_node((binary_tree_t *)parent, array[middl]);
		if (a == NULL)
			return (NULL);
		root = (avl_t *)a;
		root->left = ax_sort(root, array, begin, middl - 1);
		root->right = ax_sort(root, array, middl + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - this func create a alv tree from sorted array
 * @array: array thats sorted
 * @size: the size of the sorted array
 * Return: tree of sorted array
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
	return (NULL);
	return (ax_sort(NULL, array, 0, ((int)(size)) - 1));
}
