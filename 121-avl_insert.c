#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (int)binary_tree_height(tree->left) - (int)binary_tree_height(tree->right);
}

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->right == NULL)
        return (tree);

    new_root = tree->right;
    tree->right = new_root->left;
    if (new_root->left)
        new_root->left->parent = tree;
    new_root->left = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return (new_root);
}

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->left == NULL)
        return (tree);

    new_root = tree->left;
    tree->left = new_root->right;
    if (new_root->right)
        new_root->right->parent = tree;
    new_root->right = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return (new_root);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree to insert the value
 * @value: Value to insert in the AVL tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node = NULL;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        node = avl_insert(&((*tree)->left), value);
        (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        node = avl_insert(&((*tree)->right), value);
        (*tree)->right->parent = *tree;
    }
    else
    {
        return (NULL);  // Value already exists in the tree
    }

    // Update height and balance the tree
    int balance = binary_tree_balance(*tree);

    // Left Left Case
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);

    // Right Right Case
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);

    // Left Right Case
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }

    // Right Left Case
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return (node);
}

