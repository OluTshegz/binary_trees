#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Is a pointer to the node to measure the depth
 * Return: The depth of a node or 0 if the tree is NULL
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	depth = binary_tree_depth(tree->parent) + 1;
	return (depth);
}
