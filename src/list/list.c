# include "list.h"

/**
 * @brief Allocates a new list in the heap
 *
 * Remember to free the list using list_delete (&lst);
 *
 * @return list The list
 */
list new_list ()
{
    list lst = malloc (1 * sizeof (list));
    if (lst == NULL)
        return NULL;
    lst->element = NULL;
    lst->top = 0;
    lst->length = 0;
    return lst;
}

/**
 * @brief Get length of the list
 *
 * If list is NULL, returns 0
 *
 * @param lst The list
 * @return uint64_t The length
 */
uint64_t list_getlen (list lst)
{
    if (lst == NULL)
        return 0;
    return lst->length;
}

/**
 * @brief Pushes a value to the list and returns true
 *
 * @param list The list
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool list_push (list lst, int64_t element)
{
    if (lst == NULL)
        return false;
    lst->element = realloc (lst->element, ++(lst->length) * sizeof (lst->element[0]));
    if (lst->element == NULL)
        return false;
    if (lst->length > 1)
        lst->top++;
    lst->element[lst->top] = element;
    return true;
}

/**
 * @brief Inserts a value to a list index and returns true
 *
 * @param list The list
 * @param int64_t Value to insert
 * @param uint64_t Where to insert
 * @return bool -- true if successful
 */
bool list_insert (list lst, uint64_t index, int64_t element)
{
    if (lst == NULL)
        return false;
    lst->element = realloc (lst->element, ++(lst->length) * sizeof (lst->element[0]));
    if (lst->element == NULL)
        return false;
    if (lst->length > 1)
        lst->top++;
    lst->element[lst->top] = element;
    return true;
}

/**
 * @brief Pops a value from list and returns it
 *
 * If pop fails, LIST_UNDERFLOW  value is returned.
 *
 * When last element of list gets popped, consecutive list_pop calls
 * will return LIST_UNDERFLOW.
 *
 * There's no way to be sure that LIST_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been popped from
 * the list.
 *
 * Thus, you should know: LIST_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param list The list
 * @return int64_t -- Popped value, if failed, LIST_UNDERFLOW  is returned
 */
int64_t list_pop (list lst)
{
    if (lst == NULL)
        return LIST_UNDERFLOW ;
    if (lst->element == NULL)
        return LIST_UNDERFLOW ;
    int64_t element = lst->element[lst->top];
    if (lst->length > 1)
        lst->top--;
    lst->length--;
    if (lst->length == 0) {
        free (lst->element);
        lst->element = NULL;
    } else {
        lst->element = realloc (lst->element, (lst->length) * sizeof (lst->element[0]));
    }
    return element;
}

/**
 * @brief Peeks to a value in list and returns it
 *
 * When last element of list gets popped, consecutive list_peek calls
 * will return LIST_UNDERFLOW.
 *
 * There's no way to be sure that LIST_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been peeked to
 * from the list.
 *
 * Thus, you should know: LIST_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param list The list
 * @return int64_t -- Peeked value, if failed, LIST_UNDERFLOW  is returned
 */
int64_t list_peek (list lst)
{
    if (lst == NULL)
        return LIST_UNDERFLOW;
    if (lst->element == NULL)
        return LIST_UNDERFLOW;
    return lst->element[lst->top];
}

/**
 * @brief Gets value from an index of list
 *
 * If index < 0, returns LIST_UNDERFLOW = 0x0123456789abcdeful
 * if index > lst->length, returns LIST_OUTOFBOUNDS = 0xfedcba9876543210ul
 *
 * There's no way to be sure if any those error values were returned as a
 * result of error, or if that exact number had actually been present in
 * the list.
 *
 * @param list The list
 * @param uint64_t index The index from where value is to be returned
 * @return int64_t -- The value
 */
int64_t list_get (list lst, uint64_t index)
{
    if (index < 0)
        return LIST_UNDERFLOW;
    if (index > lst->length)
        return LIST_OUTOFBOUNDS;
    return lst->element[index];
}

/**
 * @brief Sets value to an index of list
 *
 * @param list The list
 * @param uint64_t index The index to where value is to be set
 * @param int64_t value The value to be set at the index
 * @return bool -- false if fails
 */
bool list_set (list lst, uint64_t index, int64_t value)
{
    if (index < 0)
        return false;
    if (index > lst->length)
        return false;
    lst->element[index] = value;
    return true;
}

/**
 * @brief Prints list content
 *
 * @param list The list
 * @return bool -- false if print failed
 */
bool list_print (list lst)
{
    if (lst == NULL)
        return false;
    if (lst->element == NULL)
        return false;
    for (uint64_t i = 0; i < lst->length; i++) {
        printf ("%" PRIu64 " ", lst->element[i]);
    }
    printf ("\n");
    return true;
}

/**
 * @brief True if empty
 *
 * @param list The list
 * @return bool -- True if empty
 */
bool list_isempty (list lst)
{
    return lst->top == 0 && lst->length == 0;
}

/**
 * @brief Deletes a list
 *
 * This function is basically a wrapper around free().
 * Also sets list pointer to NULL.
 *
 * This function is recommended over free as the programmer
 * might forget to set list pointer to NULL. As a result,
 * another list operation will cause some undefined behaviour.
 *
 * @param list* Reference to the list, is set to NULL.
 */
void list_delete (list *lst)
{
    if (*lst == NULL || lst == NULL)
        return;
    free (*lst);
    *lst = NULL;
}
