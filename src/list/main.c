# include <stdio.h>
# include "list.h"

int main ()
{
    list lst = new_list ();

    list_push (lst, 45);
    list_push (lst, 25);
    list_push (lst, 19);
    list_push (lst, 38);
    list_push (lst, 90);
    list_push (lst, 13);
    list_push (lst, 47);
    list_push (lst, 36);

    printf ("Before set: ");
    list_print (lst);

    printf ("Value at i4 = %ld\n", list_get (lst, 4));
    list_set (lst, 4, 474);

    printf ("After set: ");
    list_print (lst);

    list_delete (&lst);
    return 0;
}
