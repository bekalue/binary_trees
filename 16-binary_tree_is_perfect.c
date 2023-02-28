#include "binary_trees.h"

/**
 * is_perfect - checks tree's perfectness by updating leave and height count.
 * @tree: a pointer to the root node of the tree to check.
 * @leaves: a pointer to the leaves count value.
 * @height: a pointer to the tree's height value.
 * @h: the accumulated height of the current path in the tree.
 */
void is_perfect(const binary_tree_t *tree, int *leaves, int *height, int h)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
		{
			if (leaves)
				(*leaves)++;
			if (height && (h > *height))
				*height = h;
		}
		else
		{
			is_perfect(tree->left, leaves, height, h + 1);
			is_perfect(tree->right, leaves, height, h + 1);
		}
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if its perfect or 0 if tree is NULL or tree is imperfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaves = 0;
	int height = 0;

	is_perfect(tree, &leaves, &height, 0);
	return (leaves == (1 << height) ? 1 : 0);
}
