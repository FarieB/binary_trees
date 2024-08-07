#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node = NULL;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = (bst_t *)binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            new_node = (bst_t *)binary_tree_node(*tree, value);
            (*tree)->left = new_node;
            return (new_node);
        }
        else
        {
            return (bst_insert(&((*tree)->left), value));
        }
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            new_node = (bst_t *)binary_tree_node(*tree, value);
            (*tree)->right = new_node;
            return (new_node);
        }
        else
        {
            return (bst_insert(&((*tree)->right), value));
        }
    }

    return (NULL); /* Value already exists in the tree */
}

