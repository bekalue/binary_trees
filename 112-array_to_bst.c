#include "binary_trees.h"


bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 1;
	bst_t *root;

	if (!array)
		return (NULL);

	root = binary_tree_node(NULL, *array);
	while (i < size)
	{
		bst_insert(&root, *(array + i));
	}
	return (root);
}
