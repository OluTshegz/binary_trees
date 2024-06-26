#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Is a pointer to the first element of the array to be converted
 * @size: Is the number of element in the array
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
*/

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
