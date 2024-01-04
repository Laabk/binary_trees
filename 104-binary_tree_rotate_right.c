#include "binary_trees.h"

/**
 * binary_tree_rotate_right - this rotates the binary tree towards right
 * @tree: root node of the all tree
 * Return: pointer to the new node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *center;

	if (tree == NULL || tree->left == NULL)
	{
	return (NULL);
	}
	center = tree->left;
	tree->left = center->right;
	if (center->right != NULL)
	{
	center->left->parent = tree;
	}
	center->right = tree;
	center->parent = tree->parent;
	tree->parent = center;
	return (center);
}
