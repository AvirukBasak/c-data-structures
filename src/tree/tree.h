# ifndef TREE_H
# define TREE_H 1

# include <stdlib.h>
# include <inttypes.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>

# define TREE_ERROR 0x0123456789abcdeful

typedef char* string;
typedef struct _tree_node* tree;

typedef struct _tree_node {
    string name;
    int64_t value;
    tree parent;
    uint64_t childcount;
    tree *children;
} _tree_node;

/**
 * @brief Allocates a new tree in the heap
 *
 * Remember to free the tree using tree_delete (&tr);
 *
 * @return tree
 */
tree new_tree();

/**
 * @brief Sets data of a node
 * @param tr The tree root
 * @param path Path to target node
 * @param val Value to be set at target node
 * @return bool True if successful
 */
bool tree_setdata (tree tr, const string path, int64_t val);

/**
 * @brief Gets data of a node
 * @param tr The tree root
 * @param path Path to target node
 * @return int64_t Returns TREE_ERROR on error
 */
int64_t tree_getdata (tree tr, const string path);

/**
 * @brief Sets node to another node
 *
 * WARNING:
 * This method allows circular reference & and setting of one tree
 * root to the node of another tree. Abuse of this function will
 * only result in hellish mental pain.
 *
 * NOTE:
 * Circular references may result in infinite recursive calls when
 * using tree_delete or tree_rmnode. In such cases, you'll need to
 * write your own deletion function.
 *
 * @param tr The tree root
 * @param path Path to target node
 * @param node2 The node to be set to at target node
 * @return bool True if successful
 */
bool tree_setnode (tree tr, const string path, tree node2);

/**
 * @brief Gets target node
 * @param tr The tree root
 * @param path Path to target node
 * @return tree
 */
tree tree_getnode (tree tr, const string path);

/**
 * @brief Deletes a node
 * @param tr The tree root
 * @param path Path to target node
 * @return bool True if successful
 */
bool tree_rmnode (tree tr, const string path);

/**
 * @brief Deletes a tree
 *
 * This function is basically a wrapper around free().
 * Also sets tree pointer to NULL.
 *
 * This function is recommended over free as the programmer
 * might forget to set tree pointer to NULL. As a result,
 * another tree operation will cause some undefined behaviour.
 * Additionally, this function is more convenient.
 *
 * @param tree* Reference to the tree, is set to NULL.
 */
void tree_delete (tree *root);

# endif
