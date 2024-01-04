#include "binary_trees.h"

/**
 * binary_tree_insert_left - adds a node to the left of parent or
 * add the new node first of rhe parent if node exist in left
 * @parent: parent of the node at that positin
 * @value: value of the node to be stored
 * Return: NULLfor fails else return the new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *leaf_nde;

	if (parent == NULL)
	{
	return (NULL);
	}

	leaf_nde = binary_tree_node(parent, value);
	if (leaf_nde == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		leaf_nde->left = parent->left;
		parent->left->parent = leaf_nde;
	}
	parent->left = leaf_nde;
	return (leaf_nde);
}
