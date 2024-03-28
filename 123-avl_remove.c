#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_minimum - Finds the minimum node in a tree
 * @root: Is a pointer to the first node of the tree
 * Return: The node that contains the minimum value
*/

bst_t *find_minimum(bst_t *root)
{
	if (root == NULL)
	return (NULL);

	if (root->left == NULL)
		return (root);

	return (find_minimum(root->left));
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Isa pointer to the root node of the tree for removing a node
 * @value: Is the value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree
 * after removing the desired value, and after rebalancing
*/

avl_t *avl_remove(avl_t *root, int value)
{
	bst_t *successor = NULL, *temp = NULL;

	if (root == NULL)
		return (NULL);

	if (value == root->n)
	{
		if (root->right == NULL && root->left == NULL)
		{
			free(root);
			return (NULL);
		}
		if (root->right == NULL)
		{
			temp = root->left;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else
		{
			successor = find_minimum(root->right);
			root->n = successor->n;
			root->right = avl_remove(root->right, successor->n);
		}
		make_tree_avl(&root);
	}

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	return (root);
}
