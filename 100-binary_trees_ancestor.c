#include "binary_trees.h"

/**
 * binary_trees_ancestor - this function that ensures an ancestor
 * @first: the first node
 * @second: the second node
 * Return: the ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *pa, *un;

	if (first == NULL || second == NULL)
	{
	return (NULL);
	}
	if (first == second)
	{
	return ((binary_tree_t *)first);
	}

	pa = first->parent;
	un = second->parent;
	if (pa == NULL || first == un || (!pa->parent && un))
	{
	return (binary_trees_ancestor(first, un));
	}
	else if (un == NULL || pa == second || (!un->parent && pa))
	{
	return (binary_trees_ancestor(pa, second));
	}
	return (binary_trees_ancestor(pa, un));
}
