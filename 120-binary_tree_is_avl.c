#include "binary_trees.h"

/**
 * max - Computes the maximum of two numbers
 * @a: The first number
 * @b: The second number
 *
 * Return: The maximum of the two numbers
 */
static int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree
 */
static int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value allowed
 * @max: Pointer to the maximum value allowed
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
static int is_bst(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
    if (tree == NULL)
        return (1);

    if (min != NULL && tree->n <= min->n)
        return (0);
    if (max != NULL && tree->n >= max->n)
        return (0);

    return (is_bst(tree->left, min, tree) && is_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    if (!is_bst(tree, NULL, NULL))
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (abs(left_height - right_height) > 1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}

