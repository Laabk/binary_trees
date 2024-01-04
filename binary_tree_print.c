#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * print_t - this func stores recursively each level in an
 * array of strings
 * @tree: the pointer t node that is to print
 * @offset: Offset
 * @depth: Depth
 * @s: Buffer to store
 * Return: length
 *
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width; 
	int left, right, is_left;
	int d;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (d = 0; d < width; d++)
		s[depth][offset + left + d] = b[d];
	if (depth && is_left)
	{
		for (d = 0; d < width + right; d++)
			s[depth - 1][offset + left + width / 2 + d] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (d = 0; d < left + width; d++)
			s[depth - 1][offset - width / 2 + d] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - this func measures the height of a binary tree
 * @tree: the pointer to the node of the height
 * Return: the height of the tree starting at @node
 */

static size_t _height(const binary_tree_t *tree)
{
	size_t height_le;height_ri;

	height_le = tree->left ? 1 + _height(tree->left) : 0;
	height_ri = tree->right ? 1 + _height(tree->right) : 0;
	return (height_le > height_ri ? height_le : height_ri);
}

/**
 * binary_tree_print - the function that prints a binary tree
 * @tree: the pointer to the root node of tree to print
 */

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t he;
	size_t m, d;

	if (!tree)
		return;
	he = _height(tree);
	s = malloc(sizeof(*s) * (he + 1));
	if (!s)
		return;
	for (d = 0; d < he + 1; d++)
	{
		s[d] = malloc(sizeof(**s) * 255);
		if (!s[d])
			return;
		memset(s[d], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (d = 0; d < he + 1; d++)
	{
		for (m = 254; m > 1; --m)
		{
			if (s[d][m] != ' ')
				break;
			s[d][m] = '\0';
		}
		printf("%s\n", s[d]);
		free(s[d]);
	}
	free(s);
}
