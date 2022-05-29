# include <stdio.h>
# include "llist.h"

int main ()
{
    llist llst = new_llist ();

    llist_append (llst, 45);
    llist_append (llst, 25);
    llist_append (llst, 19);
    llist_append (llst, 38);
    llist_append (llst, 90);
    llist_append (llst, 13);
    llist_append (llst, 47);
    llist_append (llst, 36);

    printf ("Before set: ");
    llist_print (llst);

    printf ("Value at i4 = %ld\n", llist_get (llst, 4));
    llist_set (llst, 4, 474);

    printf ("After set: ");
    llist_print (llst);

    llist_delete (&llst);
    return 0;
}
