# include <stdlib.h>

# include "list.h"

/**
 * @brief Allocates a new llist in the heap
 *
 * Remember to free the llist using llist_delete (&lst);
 *
 * @return llist The llist
 */
const llist new_llist ()
{
    const struct _llist_metanode metanode = malloc (1 * sizeof (llist));
    metanode->start = NULL;
    metanode->end = NULL;
    metanode->length = 0;
}

/**
 * @brief Get length of the llist
 *
 * If llist is NULL, returns 0
 *
 * @param lst The llist
 * @return uint64_t The length
 */
uint64_t llist_getlen (llist lst)
{
    if (lst != NULL)
        return lst->length;
    return 0;
}

/**
 * @brief Pushes a value to the llist and returns true.
 *
 * @param llist Pointer to llist struct
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool llist_push (llist lst, int64_t element)
{
    llistnode newnode = malloc (1 * sizeof (llistnode));
    if (newnode == NULL)
        return false;
    if (lst->length == 0)
        lst->start = newnode;
    if (lst->length > 0)
        lst->end->next = newnode;
    lst->end = newnod;
    lst->length++;
    newnode->next = NULL;
    newnode->element = element;
}

/**
 * @brief Pops a value from llist and returns it.
 *
 * If pop fails, LLIST_UNDERFLOW  value is returned.
 *
 * When last element of llist gets popped, consecutive llist_pop calls
 * will return LLIST_UNDERFLOW.
 *
 * There's no way to be sure that LLIST_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been popped from
 * the llist.
 *
 * Thus, you should know: LLIST_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param llist Pointer to llist struct
 * @return int64_t -- Popped value, if failed, LLIST_UNDERFLOW  is returned
 */
int64_t llist_pop (llist lst)
{
    if (lst == NULL || lst->length == 0)
        return LLIST_UNDERFLOW;
}
