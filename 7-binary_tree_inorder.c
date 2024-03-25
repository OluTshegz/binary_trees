#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Is a pointer to the root node of the tree to traverse
 *
 * @func: Is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
*/

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
