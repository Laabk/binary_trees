#include "binary_trees.h"

/**
 * binary_tree_rotate_left - this rotates the binary tree towards right
 * @tree: root node of the all tree
 * Return: pointer to the new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *center;

	if (tree == NULL || tree->right == NULL)
	{
	return (NULL);
	}
	center = tree->right;
	tree->right = center->left;
	if (center->left != NULL)
	{
	center->left->parent = tree;
	}
	center->left = tree;
	center->parent = tree->parent;
	tree->parent = center;
	return (center);
}
