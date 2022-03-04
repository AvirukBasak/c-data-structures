# include <stdio.h>
# include "llist.h"

int main ()
{
    llist llst = new_llist ();

    llist_push (llst, 45);
    llist_push (llst, 25);
    llist_push (llst, 19);
    llist_push (llst, 38);
    llist_push (llst, 90);
    llist_push (llst, 13);
    llist_push (llst, 47);
    llist_push (llst, 36);

    printf ("Before set: ");
    llist_print (llst);

    printf ("Value at i4 = %ld\n", llist_get (llst, 4));
    llist_set (llst, 4, 474);

    printf ("After set: ");
    llist_print (llst);

    llist_delete (&llst);
    return 0;
}
