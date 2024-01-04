#include "binary_trees.h"
/**
 * binary_tree_preorder - printing tree elements using pre-order traversal
 * @tree: the tree that contains the elemn=ents
 * @func: the passed function
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
	return;
	}
	{
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
	}
}
