# include <stdio.h>
# include "tree.h"

typedef char charr[1025];

int main ()
{
    tree tr = new_tree();
    tree tr2 = new_tree();

    charr n1_n2_n3 = "/node1/node2/node3";
    charr n1_n2_n4 = "/node1/node2/node4";
    charr n1_n2 = "/node1/node2";
    charr n1 = "/node2-";

    // auto creates a named node
    tree_setdata (tr, n1_n2_n3, 45);
    tree_setdata (tr, n1_n2_n4, 25);
    tree_setdata (tr, n1_n2, 19);

    // will replace the subtree at node1 with tr2
    tree_setnode (tr, n1, tr2);

    // returns data
    int64_t value = tree_getdata (tr, n1_n2);

    // returns a subtree
    tree subtree = tree_getnode (tr, n1_n2);
    subtree->value = value;

    // deletes the node b
    tree_rmnode (tr, n1_n2);

    tree_delete (&tr);
    tree_delete (&tr2);
    return 0;
}
