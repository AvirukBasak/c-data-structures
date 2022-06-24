# include "tree.h"

tree tree_glvnip (tree node, const string path, uint64_t *index);
tree tree_mknode (tree tr, const string path);

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
    root->childcount = 0;
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
 * @return tree Returns NULL if path doesn't exist
 */
tree tree_getnode (tree node, const string path)
{
    string token = strtok (path, "/");
    while (token) {
        uint64_t i = 0;
        for (i = 0; i < node->childcount; i++) {
            if (!strcmp (node->children[i]->name, token)) {
                token = strtok (NULL, "/");
                node = node->children[i];
                break;
            }
        }
        if (!node->parent->children[i -1])
            return NULL;
    }
    return node;
}

/**
 * @brief Returns last valid node in path string: tree_get_last_valid_node_in_path
 * @param node The node from where to traverse tree
 * @param path Path to node
 * @param index Pointer to uint64_t variable, holds index of returned node in children array of the parent
 */
tree tree_glvnip (tree node, const string path, uint64_t *index)
{
    string token = strtok (path, "/");
    while (token) {
        uint64_t i = 0;
        for (i = 0; i < node->childcount; i++) {
            if (!strcmp (node->children[i]->name, token)) {
                token = strtok (NULL, "/");
                node = node->children[i];
                *index = i;
                break;
            }
        }
        if (!node->parent->children[i -1]) {
            *index = TREE_ERROR;
            break;
        }
    }
    return node;
}

/**
 * @brief Creates nodes based on path string, already created nodes are unaffected
 * @return The last newly created node
 */
tree tree_mknode (tree tr, const string path)
{
    uint64_t index;
    tree node = tree_glvnip (tr, path, &index);
    if (!node)
        return NULL;
    // tree parent = node->parent;
    string token = strtok (path, "/");
    bool flag_start = false;
    while (token) {
        if (!flag_start && strcmp (token, node->name)) {
            flag_start = true;
        }
        if (flag_start) {
            node->children = realloc (node->children, sizeof (struct _tree_node) * ++(node->childcount));
            node->children[node->childcount -1] = new_tree();
            tree newnode = node->children[node->childcount -1];
            newnode->name = token;
            newnode->parent = node;
            node = newnode;
        }
        token = strtok (NULL, "/");
    }
    if (!flag_start)
        return NULL;
    return node;
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
        for (uint64_t i = 0; i < (*root)->childcount; i++) {
            tree_delete (&((*root)->children[i]));
        }
    } else {
        free (*root);
        *root = NULL;
    }
}
