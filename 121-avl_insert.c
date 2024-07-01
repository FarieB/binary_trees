#include "binary_trees.h"

/**
 * update_height - Update the height of a node.
 * @node: Pointer to the node to update.
 */
void update_height(avl_t *node)
{
    size_t height_left = 0, height_right = 0;

    if (node->left)
        height_left = binary_tree_height(node->left) + 1;
    if (node->right)
        height_right = binary_tree_height(node->right) + 1;
    node->height = (height_left > height_right ? height_left : height_right);
}

/**
 * balance_factor - Calculate the balance factor of a node.
 * @node: Pointer to the node to calculate.
 * Return: Balance factor of the node.
 */
int balance_factor(avl_t *node)
{
    int height_left = node->left ? binary_tree_height(node->left) + 1 : 0;
    int height_right = node->right ? binary_tree_height(node->right) + 1 : 0;

    return (height_left - height_right);
}

/**
 * balance - Balance the AVL tree.
 * @tree: Double pointer to the root of the tree.
 */
void balance(avl_t **tree)
{
    int balance;

    update_height(*tree);
    balance = balance_factor(*tree);

    if (balance > 1)
    {
        if (balance_factor((*tree)->left) < 0)
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
        *tree = binary_tree_rotate_right(*tree);
    }
    else if (balance < -1)
    {
        if (balance_factor((*tree)->right) > 0)
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
        *tree = binary_tree_rotate_left(*tree);
    }
}

/**
 * bst_insert - Inserts a value in a BST
 * @tree: Double pointer to the root node of the tree to insert the value
 * @value: Value to insert in the node
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (*tree == NULL)
        return (*tree = binary_tree_node(NULL, value));

    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            (*tree)->left = binary_tree_node(*tree, value);
            return ((*tree)->left);
        }
        return (bst_insert(&((*tree)->left), value));
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            (*tree)->right = binary_tree_node(*tree, value);
            return ((*tree)->right);
        }
        return (bst_insert(&((*tree)->right), value));
    }
    return (NULL);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree to insert the value
 * @value: Value to insert in the node
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node;

    if (tree == NULL)
        return (NULL);

    node = bst_insert(tree, value);
    while (node != NULL)
    {
        balance(&node);
        if (node->parent == NULL)
            *tree = node;
        node = node->parent;
    }

    return (node);
}

