# include <stdio.h>
# include "llist.h"

void callback (int64_t i, int64_t e)
{
    printf ("i = %ld: %ld\n", i, e);
}

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

    printf ("Before set:\n");
    llist_foreach (llst, callback);

    printf ("Value at i4 = %ld\n", llist_get (llst, 4));
    llist_set (llst, 4, 474);

    printf ("After set:\n");
    llist_foreach (llst, callback);

    llist_delete (&llst);
    return 0;
}
