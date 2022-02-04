# include <stdlib.h>

# include "queue.h"

/**
 * @brief Allocates a new queue in the heap. Remember to free the queue.
 *
 * @return queue The queue
 */
queue new_queue ()
{
    queue que = malloc (1 * sizeof (queue));
    if (que == NULL)
        return NULL;
    que->element = NULL;
    que->front = 0;
    que->rear = 0;
    que->length = 0;
    return que;
}

/**
 * @brief Pushes a value to the queue and returns true.
 *
 * @param queue The queue
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool queue_push (queue que, int64_t element)
{
    if (que == NULL)
        return false;
    que->element = realloc (que->element, ++(que->length) * sizeof (que->element[0]));
    if (que->element == NULL)
        return false;
    if (que->length > 1)
        que->rear++;
    que->element[que->rear] = element;
    return true;
}

/**
 * @brief Pops a value from queue and returns it.
 *
 * If pop fails, QUEUE_UNDERFLOW  value is returned.
 *
 * When last element of queue gets popped, consecutive queue_pop calls
 * will return QUEUE_UNDERFLOW.
 *
 * There's no way to be sure that QUEUE_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been popped from
 * the queue.
 *
 * Thus, you should know: QUEUE_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param queue The queue
 * @return int64_t -- Popped value, if failed, QUEUE_UNDERFLOW  is returned
 */
int64_t queue_pop (queue que)
{
    if (que == NULL)
        return QUEUE_UNDERFLOW ;
    if (que->element == NULL)
        return QUEUE_UNDERFLOW ;
    int64_t element = que->element[que->front];
    if (que->length > 1)
        que->front++;
    que->length--;
    if (que->length == 0) {
        free (que->element);
        que->element = NULL;
        que->front = 0;
        que->rear = 0;
    }
    // else {
    //     que->element = realloc (que->element, que->length * sizeof (que->element[0]));
    // }
    return element;
}

/**
 * @brief Peeks to a value in queue and returns it
 *
 * When last element of queue gets popped, consecutive queue_peek calls
 * will return QUEUE_UNDERFLOW.
 *
 * There's no way to be sure that QUEUE_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been peeked to
 * from the queue.
 *
 * Thus, you should know: QUEUE_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param queue The queue
 * @return int64_t -- Peeked value, if failed, QUEUE_UNDERFLOW  is returned
 */
int64_t queue_peek (queue que)
{
    if (que == NULL)
        return QUEUE_UNDERFLOW;
    if (que->element == NULL)
        return QUEUE_UNDERFLOW;
    return que->element[que->front];
}

/**
 * @brief Prints queue content
 *
 * @param queue The queue
 * @return bool -- false if print failed
 */
bool queue_print (queue que)
{
    if (que == NULL)
        return false;
    if (que->element == NULL)
        return false;
    uint64_t i = que->front;
    printf ("FRONT:");
    for ( ; i < que->rear; i++) {
        printf ("%ld ", que->element[i]);
    }
    printf ("%ld:REAR\n", que->element[i]);
    return true;
}

/**
 * @brief True if empty
 *
 * @param queue The queue
 * @return bool -- True if empty
 */
bool queue_isempty (queue que)
{
    return que->front == 0 && que->rear == 0;
}

/**
 * @brief Deletes a queue
 *
 * This function is basically a wrapper around free().
 * Also sets queue pointer to NULL.
 *
 * This function is recommended over free as the programmer
 * might forget to set queue pointer to NULL. As a result,
 * another queue operation will cause some undefined behaviour.
 *
 * @param queue* Pointer to the queue, is set to NULL.
 */
void queue_delete (queue *que)
{
    if (*que == NULL || que == NULL)
        return;
    free (*que);
    *que = NULL;
}
