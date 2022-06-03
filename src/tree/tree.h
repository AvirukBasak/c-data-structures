# ifndef TREE_H
# define TREE_H 1

# include <stdlib.h>
# include <inttypes.h>
# include <stdint.h>
# include <stdbool.h>

typedef char* string;

typedef struct _tree_node {
    string name;
    int64_t value;
    struct _tree_node *parent;
    struct _tree_node *(*children);
} _tree_node;

typedef _tree_node* tree;

# endif
