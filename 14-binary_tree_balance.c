#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 *		Balance = Height of left subtree – Height of right subtree.
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 * Return: 0 if tree is NULL or the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		int right_height = 0, left_height = 0;

		right_height = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
		left_height = tree->left ? 1 + binary_tree_balance(tree->left) : 0;

		return (left_height - (right_height));

	}
	return (0);
}
