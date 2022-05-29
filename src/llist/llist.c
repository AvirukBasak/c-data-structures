# include "llist.h"

/**
 * @brief Allocates a new llist in the heap
 *
 * Remember to free the llist using llist_delete (&llst);
 *
 * @return llist The llist
 */
llist new_llist ()
{
    llist llst = malloc (1 * sizeof (struct _llist_metanode));
    if (llst == NULL)
        return NULL;
    llst->start = NULL;
    llst->end = NULL;
    llst->length = 0;
    return llst;
}

/**
 * @brief Get length of the llist
 *
 * If llist is NULL, returns 0
 *
 * @param llst The llist
 * @return uint64_t The length
 */
uint64_t llist_getlen (llist llst)
{
    if (llst != NULL)
        return llst->length;
    return 0;
}

/**
 * @brief Appends a value to the llist and returns true.
 *
 * @param llist Pointer to llist struct
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool llist_append (llist llst, int64_t element)
{
    if (llst == NULL)
        return false;
    _llist_node newnode = malloc (1 * sizeof (struct _llist_node));
    if (newnode == NULL)
        return false;
    if (llst->length == 0) {
        llst->start = newnode;
        newnode->prev = NULL;
    } else if (llst->length > 0) {
        llst->end->next = newnode;
        newnode->prev = llst->end;
    }
    newnode->next = NULL;
    newnode->element = element;
    llst->end = newnode;
    llst->length++;
    return true;
}

/**
 * @brief Pops a value from llist and returns it.
 *
 * If pop fails, LLIST_UNDERFLOW  value is returned.
 *
 * If llist_isempty (), returns LLIST_UNDERFLOW = 0x0123456789abcdeful
 * if index > llst->length, returns LLIST_OUTOFBOUNDS = 0xfedcba9876543210ul
 *
 * There's no way to be sure that LLIST_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been popped from
 * the llist.
 *
 * @param llist Pointer to llist struct
 * @return int64_t -- Popped value, if failed, LLIST_UNDERFLOW  is returned
 */
int64_t llist_pop (llist llst)
{
    if (llist_isempty(llst))
        return LLIST_UNDERFLOW;
    _llist_node node_to_pop = llst->end;
    int64_t return_val = node_to_pop->element;
    _llist_node prev_node = node_to_pop->prev;
    if (prev_node == NULL)
        llst->start = NULL;
    else
        prev_node->next = NULL;
    llst->end = prev_node;
    free (node_to_pop);
    llst->length--;
    return return_val;
}

/**
 * @brief Peeks to a value in llist and returns it
 *
 * When last element of llist gets popped, consecutive llist_peek calls
 * will return LLIST_UNDERFLOW.
 *
 * There's no way to be sure that LLIST_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been peeked to
 * from the llist.
 *
 * Thus, you should know: LLIST_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param llist Pointer to llist struct
 * @return int64_t -- Peeked value, if failed, LLIST_UNDERFLOW  is returned
 */
int64_t llist_peek (llist llst)
{
    if (llist_isempty(llst))
        return LLIST_UNDERFLOW;
    return llst->end->element;
}

/**
 * @brief Inserts a value to the llist index and returns true.
 *
 * @param llist Pointer to llist struct
 * @param uint64_t Index to where value is to be inserted
 * @param int64_t Value to insert
 * @return bool -- true if successful
 */
bool llist_insert (llist llst, uint64_t index, int64_t element)
{
    if (llst == NULL)
        return false;
    if (index > llst->length)
        return false;
    _llist_node newnode = malloc (1 * sizeof (struct _llist_node));
    if (newnode == NULL)
        return false;
    if (index == llst->length)
        return llist_append (llst, element);
    _llist_node next_node = llst->start;
    for (uint64_t i = 0; next_node != NULL; i++) {
        if (i != index)
            next_node = next_node->next;
        else
            break;
    }
    _llist_node prev_node = next_node->prev;
    if (prev_node == NULL)
        llst->start = newnode;
    else
        prev_node->next = newnode;
    newnode->prev = prev_node;
    newnode->next = next_node;
    next_node->prev = newnode;
    newnode->element = element;
    llst->length++;
    return true;
}

/**
 * @brief Removes a value from llist index and returns it.
 *
 * If remove fails, LLIST_UNDERFLOW  value is returned.
 *
 * If llist_isempty (), returns LLIST_UNDERFLOW = 0x0123456789abcdeful
 * if index > llst->length, returns LLIST_OUTOFBOUNDS = 0xfedcba9876543210ul
 *
 * There's no way to be sure that LLIST_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been removed from
 * the llist.
 *
 * @param llist Pointer to llist struct
 * @param uint64_t Index from where element is to be removed
 * @return int64_t -- Popped value, if failed, LLIST_UNDERFLOW  is returned
 */
int64_t llist_remove (llist llst, uint64_t index)
{
    return 0;
}

/**
 * @brief Gets value from an index of llist
 *
 * If llist_isempty (), returns LLIST_UNDERFLOW = 0x0123456789abcdeful
 * if index > llst->length, returns LLIST_OUTOFBOUNDS = 0xfedcba9876543210ul
 *
 * There's no way to be sure if any those error values were returned as a
 * result of error, or if that exact number had actually been present in
 * the llist.
 *
 * @param llist The llist
 * @param uint64_t index The index from where value is to be returned
 * @return int64_t -- The value
 */
int64_t llist_get (llist llst, uint64_t index)
{
    if (llist_isempty(llst))
        return LLIST_UNDERFLOW;
    if (index > llst->length - 1)
        return LLIST_OUTOFBOUNDS;
    _llist_node next_node = llst->start;
    for (uint64_t i = 0; next_node != NULL; i++) {
        if (i != index)
            next_node = next_node->next;
        else
            break;
    }
    return next_node->element;
}

/**
 * @brief Sets value to an index of llist
 *
 * @param llist The llist
 * @param uint64_t index The index to where value is to be set
 * @param int64_t value The value to be set at the index
 * @return bool -- false if fails
 */
bool llist_set (llist llst, uint64_t index, int64_t value)
{
    if (llist_isempty(llst))
        return false;
    if (index > llst->length)
        return false;
    _llist_node next_node = llst->start;
    for (uint64_t i = 0; next_node != NULL; i++) {
        if (i != index)
            next_node = next_node->next;
        else {
            next_node->element = value;
            break;
        }
    }
    return true;
}

/**
 * @brief Prints llist content
 *
 * @param llist Pointer to llist struct
 * @return bool -- false if print failed
 */
bool llist_print (llist llst)
{
    if (llist_isempty(llst))
        return false;
    _llist_node next_node = llst->start;
    while (next_node != NULL) {
        printf ("%" PRId64 " ", next_node->element);
        next_node = next_node->next;
    }
    printf ("\n");
    return true;
}

/**
 * @brief True if empty
 *
 * @param llist Pointer to llist struct
 * @return bool -- True if empty
 */
bool llist_isempty (llist llst)
{
    return llst == NULL || llst->length == 0;
}

/**
 * @brief Deletes a llist
 *
 * This function is basically a wrapper around free().
 * Also sets llist pointer to NULL.
 *
 * This function is recommended over free as the programmer
 * might forget to set llist pointer to NULL. As a result,
 * another llist operation will cause some undefined behaviour.
 *
 * @param llist* Reference to the llist, is set to NULL.
 */
void llist_delete (llist *llst)
{
    if (llist_isempty(*llst))
        return;
    _llist_node next_node = (*llst)->start;
    _llist_node bkp_node;
    while (next_node != NULL) {
        bkp_node = next_node->next;
        free (next_node);
        next_node = bkp_node;
    }
    free (*llst);
    *llst = NULL;
}
