# include "stack.h"

int main ()
{
    stack stk = new_stack ();

    stack_push (stk, 45);
    stack_push (stk, 25);
    stack_push (stk, 19);
    stack_push (stk, 38);
    stack_push (stk, 64);

    stack_print (stk);

    stack_delete (&stk);
    return 0;
}
