#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Is a pointer to the root node of the tree to count its leaves
 * Return: The number leaves
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leaves = 0;
	int right_leaves = 0;
	int left_leaves = 0;

	if (tree == NULL)
		return (0);

	left_leaves += binary_tree_leaves(tree->left);
	right_leaves += binary_tree_leaves(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	leaves = left_leaves + right_leaves;

	return (leaves);
}
