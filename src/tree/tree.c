# include "tree.h"

tree new_tree()
{
    tree root = malloc (1 * sizeof (struct _tree_node));
    root->name = NULL;
    root->value = 0;
    root->parent = NULL;
    root->children = NULL;
    return root;
}

void tree_delete (tree *root)
{
    if ((*root)->children) {
        for (uint64_t i = 0; (*root)->children[i] != NULL; i++) {
            delete_tree (&((*root)->children[i]));
        }
    } else {
        free (*root);
        *root = NULL;
    }
}
