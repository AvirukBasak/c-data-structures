# include "queue.h"

int main ()
{
    queue que = new_queue ();

    queue_push (que, 45);
    queue_push (que, 25);
    queue_push (que, 19);
    queue_push (que, 38);
    queue_push (que, 64);

    queue_print (que);

    queue_delete (&que);
    return 0;
}
