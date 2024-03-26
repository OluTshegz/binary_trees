#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Is a pointer to the root node of the tree to count its nodes
 * Return: The number of nodes with at least 1 child
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int nodes = 0;
	int right_nodes = 0;
	int left_nodes = 0;

	if (tree == NULL)
		return (0);

	left_nodes += binary_tree_nodes(tree->left);
	right_nodes += binary_tree_nodes(tree->right);

	nodes = left_nodes + right_nodes;

	if (tree->left != NULL || tree->right != NULL)
	{
		if (tree->parent == NULL)
			return (nodes);
		return (1);
	}

	return (nodes);
}
