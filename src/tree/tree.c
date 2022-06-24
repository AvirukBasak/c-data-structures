# include "tree.h"

/**
 * @brief Allocates a new tree in the heap
 *
 * Remember to free the tree using tree_delete (&tr);
 *
 * @return tree
 */
tree new_tree()
{
    tree root = malloc (1 * sizeof (struct _tree_node));
    if (!root)
        return NULL;
    root->name = "";
    root->value = 0;
    root->parent = NULL;
    root->children = NULL;
    return root;
}

/**
 * @brief Sets data of a node
 * @param tr The tree root
 * @param path Path to target node
 * @param val Value to be set at target node
 * @return bool True if successful
 */
bool tree_setdata (tree tr, const string path, int64_t val)
{
    tree node = tree_getnode (tr, path);
    if (!node) {
        tree tree_mknode (tree tr, const string path);
        node = tree_mknode (tr, path);
        if (!node)
            return false;
    }
    node->value = val;
    return true;
}

/**
 * @brief Gets data of a node
 * @param tr The tree root
 * @param path Path to target node
 * @return int64_t Returns TREE_ERROR on error
 */
int64_t tree_getdata (tree tr, const string path)
{
    tree node = tree_getnode (tr, path);
    if (!node)
        return TREE_ERROR;
    return node->value;
}

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
bool tree_setnode (tree tr, const string path, tree node2)
{
    tree node = tree_getnode (tr, path);
    if (!node)
        return false;
    // name and parent of node unchanged
    node->value = node2->value;
    if (node->children)
        free (node->children);
    node->children = node2->children;
    return true;
}

/**
 * @brief Gets target node
 * @param tr The tree root
 * @param path Path to target node
 * @return tree
 */
tree tree_getnode (tree tr, const string path)
{
    string token = strtok (path, "/");
    while (token) {
        token = strtok (path, "/");
    }
    return NULL;
}

tree tree_mknode (tree tr, const string path)
{
    return NULL;
}

/**
 * @brief Deletes a node
 * @param tr The tree root
 * @param path Path to target node
 * @return bool True if successful
 */
bool tree_rmnode (tree tr, const string path)
{
    tree node = tree_getnode (tr, path);
    if (!node)
        return false;
    tree_delete (&node);
    return true;
}

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
void tree_delete (tree *root)
{
    if ((*root)->children) {
        for (uint64_t i = 0; (*root)->children[i] != NULL; i++) {
            tree_delete (&((*root)->children[i]));
        }
    } else {
        free (*root);
        *root = NULL;
    }
}
