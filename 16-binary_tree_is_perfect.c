#include "binary_trees.h"
/**
 * tree_is_perfect - function that says if a tree is perfect or not
 * @tree: tree involved
 * Return: 0 for not a perfect else other number that is the level of height
 */

int the_tree_is_perfect(const binary_tree_t *tree)
{
	int le = 0, ri;

	ri = 0;
	if (tree->left && tree->right)
	{
		le = 1 + the_tree_is_perfect(tree->left);
		ri = 1 + the_tree_is_perfect(tree->right);
		if (ri == le && ri != 0 && le != 0)
			return (ri);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - this checkes if tree is perfect or is never a tree
 * @tree: tree involved
 * Return: 1 is it is else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int res;

	res = 0;
	if (tree == NULL)
	{
	return (0);
	}
	{
	res = the_tree_is_perfect(tree);
	if (res != 0)
	{
	return (1);
	}
	return (0);
	}
}
