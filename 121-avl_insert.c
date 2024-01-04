#include "binary_trees.h"

/**
 * root_insert_node - nthe ode value instertion in a AVL.
 * @tree: double pointer to the  root node of the AVL tree struct.
 * @parent:the  parent node of struct AVL.
 * @new: doublepointer left or right insertion.
 * @nval: insertion value
 * Return: pointer
 */
avl_t *root_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int n_val;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = root_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = root_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	n_val = binary_tree_balance(*tree);
	if (n_val > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (n_val > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (n_val < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (n_val < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - this will inserts a value into an AVL tree
 * @tree: double pointer to root node of the AVL tree to insert
 * @value: value to store in inserted node
 * Return: the inserted node else  NULL if fails.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *curr = NULL;

	if (*tree == NULL)
	{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}
	root_insert_node(tree, *tree, &curr, value);
	return (curr);
}
