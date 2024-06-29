#include "binary_trees.h"



/**
<<<<<<< HEAD
 *
 *  * binary_tree_node - function that creates a binary tree node.
 *
 *   *@parent: is a pointer to the parent node of the node to create.
 *
 *    *@value: is the value to put in the new node.
 *
 *     * Return:Your function must return a pointer to the new node or NULL if no.
 *
 *      */

=======
 * binary_tree_node - function that creates a binary tree node.
 *@parent: is a pointer to the parent node of the node to create.
 *@value: is the value to put in the new node.
 * Return:Your function must return a pointer to the new node or NULL if no.
 */
>>>>>>> d98ef629cd33422e8ae97a40718f0d76eaad39c7
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)

{
<<<<<<< HEAD

		binary_tree_t *node = malloc(sizeof(binary_tree_t));



			if (node == NULL)

						return (NULL);

				node->n = value;

					node->parent = parent;

						node->left = NULL;

							node->right = NULL;

								return (node);

=======
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
>>>>>>> d98ef629cd33422e8ae97a40718f0d76eaad39c7
}
