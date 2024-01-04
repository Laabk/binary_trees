#include "binary_trees.h"
/**
 * binary_tree_leaves - this returns the number of leaves in a tree
 * @tree: the tree involvecd
 * Return: leaf total
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_node = 0;
	size_t le = 0, ri = 0;

	if (tree == NULL)
	{
		return (0);
	}
	{
		le = binary_tree_leaves(tree->left);
		ri = binary_tree_leaves(tree->right);
		leaf_node = le + ri;
		return ((!le && !ri) ? leaf_node + 1 : leaf_node + 0);
	}
}
