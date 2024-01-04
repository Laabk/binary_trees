#include "binary_trees.h"
/**
 * binary_tree_depth - depth of a node in root
 * @tree: node for the depth
 * Return: dept
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t  dept = 0;

	while (tree && tree->parent)
	{
	dept++;
	tree = tree->parent;
	}
	return (dept);
}
