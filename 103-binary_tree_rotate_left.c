#include "binary_trees.h"

/**
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = tree, *parent;

	if (!tree || !tree->right)
		return (NULL);

	parent = tree->parent;
	tree = tree->right;
	tmp->right = tree->left;
	if (tree->left)
		tree->left->parent = tmp;
	tmp->parent = tree;
	tree->left = tmp;

	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}
