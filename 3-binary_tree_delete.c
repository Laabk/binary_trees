#include "binary_trees.h"
/**
 * binary_tree_delete - free the tree recursively freeing the node
 * with null node left and right
 * @tree: tthe memory assigned to tree
 * Return: void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
	return;
	}
	else
	{
	if (tree != NULL)
	{
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	}
	free(tree);
	}

}
