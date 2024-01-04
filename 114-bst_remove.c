#include "binary_trees.h"
/**
 * successor - this gets the next successor i mean the min node in the
 * right subtree
 * @node: the tree to find the node with val
 * Return: the min value inthe tree
 */
int successor(bst_t *node)
{
	int left;

	left = 0;
	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * two_children - thiss gets the next successor using the min
 * value in the right subtree, and then replace the node
 * @root: nodes containing two children
 * Return: the current value
 */

int two_children(bst_t *root)
{
	int cur_val = 0;

	cur_val = successor(root->right);
	root->n = cur_val;
	return (cur_val);
}
/**
 *remove_type - this function that removes a node containg its children
 *@root: the node to remove
 *Return: if 0 it has no children or other value if it has
 */

int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
	if (root->parent->right == root)
	root->parent->right = NULL;
	else
	root->parent->left = NULL;
	free(root);
	return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
	if (!root->left)
	{
	if (root->parent->right == root)
	root->parent->right = root->right;
	else
	root->parent->left = root->right;
	root->right->parent = root->parent;
	}
	if (!root->right)
	{
	if (root->parent->right == root)
	root->parent->right = root->left;
	else
	root->parent->left = root->left;
	root->left->parent = root->parent;
	}
	free(root);
	return (0);
	}
	return (two_children(root));
}
/**
 * bst_remove - this function remove a node from a BST tree
 * @root: tree root
 * @value: the node with a value to remove
 * Return: the tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int ty;

	ty = 0;

	if (root == NULL)
	return (NULL);
	if (value < root->n)
	bst_remove(root->left, value);
	else if (value > root->n)
	bst_remove(root->right, value);
	else if (value == root->n)
	{
	ty = remove_type(root);
	if (ty != 0)
	bst_remove(root->right, ty);
	}
	return (NULL);
	return (root);
}
