#include "binary_trees.h"

/**
* binary_tree_height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
		}
		return (0);
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect.
* @tree: Pointer to the root node of the tree to check.
*
* Return: 1 if the tree is perfect, 0 otherwise.
*/
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	/* If tree is NULL, it is not perfect */
	if (tree == NULL)
		return (0);

	/* If the node is a leaf, it is perfect */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/*
	* Get the height of the left and right subtrees
	* using the existing height-checking function
	*/
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/*
	* Check if the left and right
	* subtrees have the same height and are perfect
	*/
	return ((left_height == right_height) &&
	binary_tree_is_perfect(tree->left) &&
	binary_tree_is_perfect(tree->right));
}
