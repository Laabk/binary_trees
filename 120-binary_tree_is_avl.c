#include "binary_trees.h"

/**
 * binary_tree_height - this measures the height of a binary tree
 * @tree: tree containing
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t le = 0;
	size_t ri = 0;

	if (tree == NULL)
	{
		return (0);
	}
	{
		if (tree)
		{
			le = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			ri = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((le > ri) ? le : ri);
		}
}

/**
 * bal_avl - function compare each subtree if its AVL.
 * @tree: node that point to tree to find.
 * @high: node that point to the higher node
 * @lower: node that point to the lower node
 * Return: if 1 tree is AVL, 0 if not.
 */

int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_le, height_ri;
	size_t piv;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
		return (0);
		}
		height_le = binary_tree_height(tree->left);
		height_ri = binary_tree_height(tree->right);
	piv = height_le > height_ri ? height_le - height_ri : height_ri - height_le;
	if (piv > 1)
	{
	return (0);
	}
	return (bal_avl(tree->left, lower, tree->n - 1) &&
	bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - this ensures if a binary tree is a valid AVL tree.
 * @tree: the node that point to the tree to check.
 * Return: if 1 tree is AVL, 0 if not.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	{
	return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
