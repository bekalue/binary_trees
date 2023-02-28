#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling.
 *
 * Return: NULL if node is NULL, the node's parent is NULL
 *		or if node has no sibling. otherwise returns
 *	   a pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;

	if (node && node->parent)
	{
		left = node->parent->left;
		right = node->parent->right;
	}
	return (node == right ? left : right);
}
