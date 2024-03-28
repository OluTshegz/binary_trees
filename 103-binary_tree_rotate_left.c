#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_rotate_left - Berforms a left-rotation on a binary tree
 * @tree: Is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL)
		return (NULL);

	temp = tree->right;

	if (temp != NULL)
	{
		tree->right = temp->left;

		if (temp->left != NULL)
		{
			temp->left->parent = tree;
		}
		temp->parent = tree->parent;
		temp->left = tree;
		if (tree->parent)
		{
			if (tree->parent->left == tree)
				tree->parent->left = temp;
			else
			tree->parent->right = temp;
		}

		tree->parent = temp;
		tree = temp;
	}
	return (tree);
}
