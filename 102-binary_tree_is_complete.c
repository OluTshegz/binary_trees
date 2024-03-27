#include "binary_trees.h"

/**
 * height - Helper function to get the height of a node
 * @tree: Is a pointer to the root node of the tree to measure the height
 * @h: Is a pointer to the height value
 * @max_height: Is a pointer to max height value
*/
void height(const binary_tree_t *tree, int h, int *max_height)
{
	if (tree == NULL)
		return;

	h = h + 1;

	height(tree->left, h, max_height);
	height(tree->right, h, max_height);

	if (h > *max_height)
		*max_height = h;

	h = h - 1;
}

/**
 * tree_is_complete - Helper fucntion that checks if a binary tree is complete
 * @tree: Is a pointer to the root node of the tree to check
 * @is_complete: Is the check value
 * Return: 1 if the tree is complete otherwise it returns 0
*/

int tree_is_complete(const binary_tree_t *tree, int *is_complete)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL || *is_complete == 0)
		return (*is_complete);

	height(tree->left, 0, &left_height);
	height(tree->right, 0, &right_height);

	tree_is_complete(tree->left, is_complete);
	tree_is_complete(tree->right, is_complete);

	if (left_height < right_height)
		*is_complete = 0;
	else if (tree->left && tree->right)
	{
		if ((!tree->left->left || !tree->left->right)
			&& (tree->right->left || tree->right->right))
		{
			*is_complete = 0;
		}
	}

	return (*is_complete);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Is a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete otherwise it returns 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_complete = 1;

	if (tree == NULL)
		return (0);

	tree_is_complete(tree, &is_complete);

	return (is_complete);
}
