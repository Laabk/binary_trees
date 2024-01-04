#include "binary_trees.h"
/**
 * binary_tree_is_leaf - tells when a node is a leaf
 * (have no child neither left nor right)
 * @node: node which has is a leaf or not
 * Return:  if node is a leaf 1, if it is not 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	return (0);
	if (node->left == NULL && node->right == NULL)
	return (1);
	return (0);
}
