#include "binary_trees.h"

/**
 * bst_insert -  inserts a value in a Binary Search Tree
 *		 if the address stored in tree is NULL,
 *		 the created node becomes the root node.
 *		 If the value is already present in the tree,
 *		 it will be ignored.
 *
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: returns a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent, *tmp, *new_node;

	if (!tree)
		return (NULL);
	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		parent = tmp;
		if (value > tmp->n)
			tmp = tmp->right;
		else if (value < tmp->n)
			tmp = tmp->left;
		else if (value == tmp->n)
			return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (value > parent->n)
		parent->right = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	return (new_node);
}

/**
 * avl_insert - inserts a value in an AVL Tree.
 *		The resulting tree after insertion,
 *		will be a balanced AVL Tree.
 *		if the address stored in tree is NULL,
 *		the created node becomes the root node.
 *
 * @tree: a double pointer to the root node of the AVL tree
 * @value: value to insert
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;
	avl_t *node = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}
