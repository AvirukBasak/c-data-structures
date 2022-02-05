# include <stdio.h>
# include "llist.h"

int main ()
{
    llist lst = new_llist ();

    llist_push (lst, 45);
    llist_push (lst, 25);
    llist_push (lst, 19);
    llist_push (lst, 38);
    llist_push (lst, 90);
    llist_push (lst, 13);
    llist_push (lst, 47);
    llist_push (lst, 36);

    printf ("Before set: ");
    llist_print (lst);

    printf ("Value at i4 = %ld\n", llist_get (lst, 4));
    llist_set (lst, 4, 474);

    printf ("After set: ");
    llist_print (lst);

    llist_delete (&lst);
    return 0;
}
