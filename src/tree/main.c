# include <stdio.h>
# include "tree.h"

int main ()
{
    tree tr = new_tree();
    tree tr2 = new_tree();

    // auto creates a named node
    tree_setdata (tr, "/node1/node2/node3", 45);
    tree_setdata (tr, "/node1/node2/node4", 25);
    tree_setdata (tr, "/node1/node2", 19);

    // will replace the subtree at node1 with tr2
    tree_setnode (tr, "/node1", tr2);

    // returns data
    int64_t value = tree_getdata (tr, "/node1/node2");

    // returns a subtree
    tree subtree = tree_getnode (tr, "/node1/node2");
    subtree->value = value;

    // deletes the node b
    tree_rmnode (tr, "/node1/node2");

    tree_delete (&tr);
    tree_delete (&tr2);
    return 0;
}
