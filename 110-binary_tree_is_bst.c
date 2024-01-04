#include "binary_trees.h"

/**
 * find_tree_Left - finds ifthere nodes smaller than
 * the root specified
 * @node: node in the tree to find out
 * @max: value
 * Return: if 1  nodes are smaller or equal or 0 if not
 */

int find_tree_Left(const binary_tree_t *node, int max)
{
	int left = 0;
	int right = 0;

	if (node == NULL)
	{
		return (1);
	}
	{
		if (node->n >= max)
			return (0);
		left = find_tree_Left(node->left, max);
		right = find_tree_Left(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * find_tree_Right - finds if there nodes are bigger than the
 * root specified
 * @node: node in the tree to find out
 * @min: value
 * Return: if 1 all is bigger or equal or 0 if not
 */

int find_tree_Right(const binary_tree_t *node, int min)
{
	int left = 0;
	int right = 0;

	if (node == NULL)
	{
	return (1);
	}
	{
	if (node->n <= min)
	return (0);
	left = find_tree_Right(node->left, min);
	right = find_tree_Right(node->right, min);
	if (left == right && left == 1)
	return (1);
	return (0);
	}
}

/**
 * binary_tree_is_bst - tells when a tree is a bst or if is not
 * by comparing values in the right and left of tree
 * @tree: pointer to the tree to find
 * Return: if 1 it is a BST or 0 else not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int i = 0;
	int left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		i = find_tree_Left(tree->left, tree->n);
		if (i == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		i = find_tree_Right(tree->right, tree->n);
		if (i == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
