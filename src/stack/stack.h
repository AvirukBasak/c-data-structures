# ifndef STACK_H
# define STACK_H 1

# include <stdint.h>
# include <stdbool.h>

# define STACK_UNDERFLOW 0x0123456789abcdeful

struct _stack {
    uint64_t top;
    uint64_t length;
    int64_t *element;
};

/**
 * @brief The stack struct
 *
 * // new stack
 * stack stk = new_stack ();
 *
 * //functions
 * bool stack_push (stack stk, int64_t element);
 * int64_t stack_pop (stack stk);
 * int64_t stack_peek (stack stk);
 * int64_t stack_peek (stack stk);
 * bool stack_print (stack stk);
 * bool stack_isempty (stack stk);
 *
 * // avoid accessing following stack members
 * stk->top;        // stack top
 * stk->length;     // stack length
 * stk->elements;   // stack elements array
 */
typedef struct _stack *stack;

/**
 * @brief Allocates a new stack in the heap. Remember to free the stack.
 *
 * @return stack Pointer to stack struct
 */
stack new_stack ();

/**
 * @brief Pushes a value to the stack and returns true.
 *
 * @param stack Pointer to stack struct
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool stack_push (stack stk, int64_t element);

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
 * @param stack Pointer to stack struct
 * @return int64_t -- Popped value, if failed, STACK_UNDERFLOW  is returned
 */
int64_t stack_pop (stack stk);

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
 * @param stack Pointer to stack struct
 * @return int64_t -- Peeked value, if failed, STACK_UNDERFLOW  is returned
 */
int64_t stack_peek (stack stk);

/**
 * @brief Prints stack content
 *
 * @param stack Pointer to stack struct
 * @return bool -- false if print failed
 */
bool stack_print (stack stk);

/**
 * @brief True is empty
 *
 * @param stack Pointer to stack struct
 * @return bool -- True if empty
 */
bool stack_isempty (stack stk);

/**
 * @brief Deletes a stack
 *
 * This function is basically a wrapper around free().
 * Also sets stack pointer to NULL.
 *
 * This function is recommended over free as the programmer
 * might forget to set stack pointer to NULL. As a result,
 * another stack operation will cause some undefined behaviour.
 *
 * @param stack* Pointer to the stack, is set to NULL.
 */
void stack_delete (stack *stk);

# endif
