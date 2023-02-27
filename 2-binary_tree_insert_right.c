#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in.
 * @value: the value to store in the new node.
 *
 * Description: If parent already has a right-child, the new node takes
 *		its place, and the old right-child be set as the
 *		right-child of the new node.
 *
 * Return: a pointer to the created node,
 *	   or NULL on (failure or if parent is NULL)
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right_node = NULL;

	if (parent)
	{
		new_right_node = malloc(sizeof(binary_tree_t));
		if (new_right_node)
		{
			new_right_node->n = value;
			new_right_node->left = NULL;
			new_right_node->right = parent->right;
			new_right_node->parent = parent;
			if (parent->right)
				parent->right->parent = new_right_node;
			parent->right = new_right_node;
		}
	}
	return (new_right_node);
}
