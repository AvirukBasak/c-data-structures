# include "queue.h"

int main ()
{
    queue que = new_queue ();

    queue_enqueue (que, 45);
    queue_enqueue (que, 25);
    queue_enqueue (que, 19);
    queue_enqueue (que, 38);
    queue_enqueue (que, 64);

    queue_print (que);

    queue_delete (&que);
    return 0;
}
