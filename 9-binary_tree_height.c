#include "binary_trees.h"
#include <stdio.h>

/**
 * height - Helper function to get the height of a node
 * @tree: Is a pointer to the root node of the tree to measure the height
 * @h: Is a pointer to the height value
 * @max_height: Is a pointer to max height value
*/
void height(const binary_tree_t *tree, int *h, int *max_height)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return;

	*h = *h + 1;

	height(tree->left, h, max_height);
	height(tree->right, h, max_height);

	if (*h > *max_height)
		*max_height = *h;

	*h = *h - 1;
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Is a pointer to the root node of the tree to measure the height
 * Return: The height of a node or 0 of the tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	int h = 0;
	int max = 0;

	height(tree, &h, &max);
	return (max);
}
