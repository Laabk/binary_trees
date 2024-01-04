#include "binary_trees.h"

/**
 * binary_tree_is_root - this function that checks to see a node is a root
 * @node: Node that is observe to be root or not
 * Return: 0 if is not a root 1 it is root
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent == NULL)
		return (1);
	return (0);
}
