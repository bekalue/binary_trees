#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node: a pointer to the node to find the uncle.
 *
 * Return: a pointer to the uncle node or NULL (if node is NULL
 *	   or if node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;
	binary_tree_t *parent = node ? node->parent : NULL;

	if (parent && parent->parent)
	{
		left = parent->parent->left;
		right = parent->parent->right;
	}
	return (parent == left ? right : left);
}
