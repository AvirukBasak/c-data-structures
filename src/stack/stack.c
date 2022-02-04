# include <stdlib.h>

# include "stack.h"

/**
 * @brief Allocates a new stack in the heap. Remember to free the stack.
 *
 * @return stack The stack
 */
stack new_stack ()
{
    stack stk = malloc (1 * sizeof (stack));
    if (stk == NULL)
        return NULL;
    stk->element = NULL;
    stk->top = 0;
    stk->length = 0;
    return stk;
}

/**
 * @brief Pushes a value to the stack and returns true.
 *
 * @param stack The stack
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool stack_push (stack stk, int64_t element)
{
    if (stk == NULL)
        return false;
    stk->element = realloc (stk->element, ++(stk->length) * sizeof (stk->element));
    if (stk->element == NULL)
        return false;
    if (stk->length > 1)
        stk->top++;
    stk->element[stk->top] = element;
    return true;
}

/**
 * @brief Pops a value from stack and returns it.
 *
 * If pop fails, STACK_UNDERFLOW  value is returned.
 *
 * When last element of stack gets popped, consecutive stack_pop calls
 * will return STACK_UNDERFLOW.
 *
 * There's no way to be sure that STACK_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been popped from
 * the stack.
 *
 * Thus, you should know: STACK_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param stack The stack
 * @return int64_t -- Popped value, if failed, STACK_UNDERFLOW  is returned
 */
int64_t stack_pop (stack stk)
{
    if (stk == NULL)
        return STACK_UNDERFLOW ;
    if (stk->element == NULL)
        return STACK_UNDERFLOW ;
    int64_t element = stk->element[stk->top];
    if (stk->length > 1)
        stk->top--;
    stk->length--;
    if (stk->length == 0) {
        free (stk->element);
        stk->element = NULL;
    } else {
        stk->element = realloc (stk->element, (stk->length) * sizeof (stk->element));
    }
    return element;
}

/**
 * @brief Peeks to a value in stack and returns it
 *
 * When last element of stack gets popped, consecutive stack_peek calls
 * will return STACK_UNDERFLOW.
 *
 * There's no way to be sure that STACK_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been peeked to
 * from the stack.
 *
 * Thus, you should know: STACK_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param stack The stack
 * @return int64_t -- Peeked value, if failed, STACK_UNDERFLOW  is returned
 */
int64_t stack_peek (stack stk)
{
    if (stk == NULL)
        return STACK_UNDERFLOW;
    if (stk->element == NULL)
        return STACK_UNDERFLOW;
    return stk->element[stk->top];
}

/**
 * @brief Prints stack content
 *
 * @param stack The stack
 * @return bool -- false if print failed
 */
bool stack_print (stack stk)
{
    if (stk == NULL)
        return false;
    if (stk->element == NULL)
        return false;
    for (uint64_t i = 0; i < stk->length; i++) {
        printf ("%ld ", stk->element[i]);
    }
    printf (":TOP\n");
    return true;
}

/**
 * @brief True is empty
 *
 * @param stack The stack
 * @return bool -- True if empty
 */
bool stack_isempty (stack stk)
{
    return stk->top == 0 && stk->length == 1;
}

/**
 * @brief Deletes a stack
 *
 * This function is basically a wrapper around free()
 *
 * @param stack* Pointer to the stack, is set to NULL.
 */
void stack_delete (stack *stk)
{
    free (*stk);
    *stk = NULL;
}
