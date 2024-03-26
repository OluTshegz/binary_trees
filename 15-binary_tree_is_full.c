#include "binary_trees.h"

/**
 * tree_is_full - Helper function to Check if a binary tree is full
 * @tree: Is a pointer to the root node of the tree to check
 * @is_full: Is the check value
 * Return: 1 if the tree is full otherwise 0
*/
int tree_is_full(const binary_tree_t *tree, int *is_full)
{
	if (tree == NULL)
		return (*is_full);
	tree_is_full(tree->left, is_full);
	tree_is_full(tree->right, is_full);

	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		*is_full = 0;

	return (*is_full);
}


/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Is a pointer to the root node of the tree to check
 * Return: 1 if the tree is full otherwise 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (tree == NULL)
		return (0);

	return (tree_is_full(tree, &is_full));
}
