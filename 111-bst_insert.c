#include "binary_trees.h"

/**
 * bst_insert - this inserts a value in a Binary Search Tree
 * @tree: ** pointer to root node of the BST to insert the value
 * @value: the value to store in the node to insert
 * Return: pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *sec = NULL, *aux = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		sec = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}
	aux = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = aux;
	else if (value < sec->n)
	{
		sec->left = aux;
		aux->parent = sec;
	}
	else
	{
		sec->right = aux;
		aux->parent = sec;
	}

	return (aux);
}
