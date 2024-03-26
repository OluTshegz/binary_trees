#include "binary_trees.h"
#include <stdio.h>

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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor
 * Return: The balance factor or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	height(tree->left, 0, &left_height);
	height(tree->right, 0, &right_height);

	balance_factor = left_height - right_height;

	return (balance_factor);
}
