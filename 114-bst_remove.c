#include "binary_trees.h"

/**
 * right_smallest - finds smallest node from the binary search tree.
 * @root: a pointer to the root node sof the tree.
 *
 * Return: a pointer to the smallest node
 */
bst_t *right_smallest(bst_t *root)
{
	bst_t *smallest_left = root;

	while (smallest_left->left)
		smallest_left = smallest_left->left;
	return (smallest_left);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *		if the node to be deleted has two children,
 *		it will be replaced with its first in-order
 *		successor (not predecessor)
 * @root: a pointer to the root node of the tree where you will remove a node.
 * @value: value to remove in the tree.
 *
 * Return: a pointer to the new root node of the tree
 *	   after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *replace;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			replace = root->right;
			free(root);
			return (replace);
		}
		else if (!root->right)
		{
			replace = root->left;
			free(root);
			return (replace);
		}
		replace = right_smallest(root->right);
		root->n = replace->n;
		root->right = bst_remove(root->right, replace->n);
	}
	return (root);
}
