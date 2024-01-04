#include "binary_trees.h"

/**
 * binary_tree_node - this will create a binary node
 * @parent: node parent/if not first node
 * @value: Value of the node to be stored
 * Return: the leaf_node/newnode
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *leaf_nde;

	leaf_nde = malloc(sizeof(binary_tree_t));
	if (leaf_nde == NULL)
	{
	return (NULL);
	}
	leaf_nde->n = value;
	leaf_nde->parent = parent;
	leaf_nde->right = NULL;
	leaf_nde->left = NULL;
	return (leaf_nde);
}
