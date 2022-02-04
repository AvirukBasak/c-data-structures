# ifndef LIST_H
# define LIST_H 1

# include <stdint.h>
# include <stdbool.h>

# define LIST_UNDERFLOW 0x0123456789abcdeful
# define LIST_OUTOFBOUNDS 0xfedcba9876543210ul

struct _list {
    uint64_t top;
    uint64_t length;
    int64_t *element;
};

/**
 * @brief The list struct
 *
 * // new list
 * list lst = new_list ();
 *
 * //functions
 * uint64_t list_getlen (list lst);
 * bool list_push (list lst, int64_t element);
 * int64_t list_pop (list lst);
 * int64_t list_peek (list lst);
 * int64_t list_get (list lst, uint64_t index);
 * bool list_set (list lst, uint64_t index, int64_t value);
 * bool list_print (list lst);
 * bool list_isempty (list lst);
 *
 * // deleting list
 * void list_delete (list *lst);
 *
 * // avoid accessing following list members
 * lst->top;        // list top
 * lst->length;     // list length
 * lst->elements;   // list elements array
 */
typedef struct _list *list;

/**
 * @brief Allocates a new list in the heap
 *
 * Remember to free the list using list_delete (&lst);
 *
 * @return list The list
 */
list new_list ();

/**
 * @brief Get length of the list
 *
 * If list is NULL, returns 0
 *
 * @param lst The list
 * @return uint64_t The length
 */
uint64_t list_getlen (list lst);

/**
 * @brief Pushes a value to the list and returns true.
 *
 * @param list Pointer to list struct
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool list_push (list lst, int64_t element);

/**
 * @brief Pops a value from list and returns it.
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
 * @param list Pointer to list struct
 * @return int64_t -- Popped value, if failed, LIST_UNDERFLOW  is returned
 */
int64_t list_pop (list lst);

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
 * @param list Pointer to list struct
 * @return int64_t -- Peeked value, if failed, LIST_UNDERFLOW  is returned
 */
int64_t list_peek (list lst);

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
int64_t list_get (list lst, uint64_t index);

/**
 * @brief Sets value to an index of list
 *
 * @param list The list
 * @param uint64_t index The index to where value is to be set
 * @param int64_t value The value to be set at the index
 * @return bool -- false if fails
 */
bool list_set (list lst, uint64_t index, int64_t value);

/**
 * @brief Prints list content
 *
 * @param list Pointer to list struct
 * @return bool -- false if print failed
 */
bool list_print (list lst);

/**
 * @brief True if empty
 *
 * @param list Pointer to list struct
 * @return bool -- True if empty
 */
bool list_isempty (list lst);

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
void list_delete (list *lst);

# endif
