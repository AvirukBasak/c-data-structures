# ifndef LLIST_H
# define LLIST_H 1

# include <stdint.h>
# include <stdbool.h>

# define LLIST_UNDERFLOW 0x0123456789abcdeful
# define LLIST_OUTOFBOUNDS 0xfedcba9876543210ul

// first node of llist
struct _llist_metanode {
    struct _llist_node *start;  // pointer to starting node
    struct _llist_node *end;    // pointer to ending node
    uint64_t length;            // 1st node always stores size of list and certain meta data
};

typedef struct _llist_node {
    struct _llist *next;
    int64_t element;
} *llistnode;

/**
 * @brief The llist struct
 *
 * // new llist
 * llist lst = new_llist ();
 *
 * //functions
 * uint64_t llist_getlen (llist lst);
 * bool llist_push (llist lst, int64_t element);
 * int64_t llist_pop (llist lst);
 * int64_t llist_peek (llist lst);
 * int64_t llist_get (llist lst, uint64_t index);
 * bool llist_set (llist lst, uint64_t index, int64_t value);
 * bool llist_print (llist lst);
 * bool llist_isempty (llist lst);
 *
 * // deleting llist
 * void llist_delete (llist *lst);
 *
 * // avoid accessing following llist members
 * lst->next;       // llist next
 * lst->elements;   // llist element
 */
typedef llistnode llist;

/**
 * @brief Allocates a new llist in the heap
 *
 * Remember to free the llist using llist_delete (&lst);
 *
 * @return llist The llist
 */
llist new_llist ();

/**
 * @brief Get length of the llist
 *
 * If llist is NULL, returns 0
 *
 * @param lst The llist
 * @return uint64_t The length
 */
uint64_t llist_getlen (llist lst);

/**
 * @brief Pushes a value to the llist and returns true.
 *
 * @param llist Pointer to llist struct
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool llist_push (llist lst, int64_t element);

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
int64_t llist_pop (llist lst);

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
int64_t llist_peek (llist lst);

/**
 * @brief Gets value from an index of llist
 *
 * If index < 0, returns LLIST_UNDERFLOW = 0x0123456789abcdeful
 * if index > lst->length, returns LLIST_OUTOFBOUNDS = 0xfedcba9876543210ul
 *
 * There's no way to be sure if any those error values were returned as a
 * result of error, or if that exact number had actually been present in
 * the llist.
 *
 * @param llist The llist
 * @param uint64_t index The index from where value is to be returned
 * @return int64_t -- The value
 */
int64_t llist_get (llist lst, uint64_t index);

/**
 * @brief Sets value to an index of llist
 *
 * @param llist The llist
 * @param uint64_t index The index to where value is to be set
 * @param int64_t value The value to be set at the index
 * @return bool -- false if fails
 */
bool llist_set (llist lst, uint64_t index, int64_t value);

/**
 * @brief Prints llist content
 *
 * @param llist Pointer to llist struct
 * @return bool -- false if print failed
 */
bool llist_print (llist lst);

/**
 * @brief True if empty
 *
 * @param llist Pointer to llist struct
 * @return bool -- True if empty
 */
bool llist_isempty (llist lst);

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
void llist_delete (llist *lst);

# endif
