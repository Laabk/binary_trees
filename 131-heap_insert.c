#include "binary_trees.h"

/**
 * heap_insert - ithis inserts a va in Max Binary Heap
 * @root: the root node of the Heap to insert the value
 * @value: the value to store in node
 * Return: the created node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *curr, *cha;
	int size, le;
	int rem, bit, lev, temp;

	if (!root)
	return (NULL);
	if (!(*root))
	return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	le = size;
	for (lev = 0, rem = 1; le >= rem; rem *= 2, lev++)
		le -= rem;
	for (bit = 1 << (lev - 1); bit != 1; bit >>= 1)
		tree = le & bit ? tree->right : tree->left;

	curr = binary_tree_node(tree, value);
	le & 1 ? (tree->right = curr) : (tree->left = curr);
	cha = curr;
	for (; cha->parent && (cha->n > cha->parent->n); cha = cha->parent)
	{
		temp = cha->n;
		cha->n = cha->parent->n;
		cha->parent->n = temp;
		curr = curr->parent;
	}
	return (curr);
}

/**
 * binary_tree_size - this func measures the size of a binary tree
 * @tree: tree size
 * Return: size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
