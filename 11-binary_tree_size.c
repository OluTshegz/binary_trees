#include "binary_trees.h"

/**
 * tree_size - Helper function to measure the size of a binary tree
 * @tree: Is a pointer to the root node of the tree to measure the size
 * @size: Is a pointer to the size value
*/

void tree_size(const binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
		return;

	tree_size(tree->left, size);
	tree_size(tree->right, size);
	*size = *size + 1;
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Is a pointer to the root node of the tree to measure the size
 * Return: The size of the tree
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	tree_size(tree, &size);
	return (size);
}
