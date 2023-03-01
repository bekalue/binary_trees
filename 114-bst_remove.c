#include "binary_trees.h"

bst_t *right_smallest(bst_t *root)
{
	bst_t *smallest_left = root;

	while (smallest_left->left)
		smallest_left = smallest_left->left;
	return (smallest_left);
}

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *replace;

	if (!root || !value)
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
