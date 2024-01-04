#include "binary_trees.h"
/**
 * binary_tree_insert_right - add a node in the right of the parent
 * else add the new node first at the bottom if node exist
 * @parent: parent of the node at the positin
 * @value: value of the node to  be stored
 * Return: NULL for fails else the new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		leaf_nde->right = parent->right;
		parent->right->parent = leaf_nde;
	}
	parent->right = leaf_nde;
	return (leaf_nde);
}
