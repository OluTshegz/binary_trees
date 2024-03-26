#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Is a pointer to the node to find the uncle
 * Return: A pointer to the uncle node
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL)
		return (NULL);

	parent = node->parent;

	if (parent == NULL || parent->parent == NULL)
		return (NULL);

	if (parent->parent->left == parent)
		return (parent->parent->right);
	else
		return (parent->parent->left);
}
