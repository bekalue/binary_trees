#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 *			A NULL pointer is not a node
 * @tree: a pointer to the root node of the tree to count the number of nodes
 *
 * Return: 0 If tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
			return (0);
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
	}
	return (0);
}
