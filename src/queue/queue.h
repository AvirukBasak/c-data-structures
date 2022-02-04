# ifndef QUEUE_H
# define QUEUE_H 1

# include <stdint.h>
# include <stdbool.h>

# define QUEUE_UNDERFLOW 0x0123456789abcdeful

struct _queue {
    uint64_t front;
    uint64_t rear;
    uint64_t length;
    int64_t *element;
};

/**
 * @brief The queue struct
 *
 * // new queue
 * queue que = new_queue ();
 *
 * //functions
 * bool queue_push (queue que, int64_t element);
 * int64_t queue_pop (queue que);
 * int64_t queue_peek (queue que);
 * bool queue_print (queue que);
 * bool queue_isempty (queue que);
 *
 * // deleting queue
 * void queue_delete (queue *que);
 *
 * // avoid accessing following queue members
 * que->front;      // queue front
 * que->rear;       // queue rear
 * que->length      // queue length
 * que->elements;   // queue elements array
 */
typedef struct _queue *queue;

/**
 * @brief Allocates a new queue in the heap
 *
 * Remember to free the queue using queue_delete (&que);
 *
 * @return queue The queue
 */
queue new_queue ();

/**
 * @brief Pushes a value to the queue and returns true
 *
 * @param queue Pointer to queue struct
 * @param int64_t Value to push
 * @return bool -- true if successful
 */
bool queue_push (queue que, int64_t element);

/**
 * @brief Pops a value from queue and returns it
 *
 * If pop fails, queue_UNDERFLOW  value is returned.
 *
 * When last element of queue gets popped, consecutive queue_pop calls
 * will return queue_UNDERFLOW.
 *
 * There's no way to be sure that queue_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been popped from
 * the queue.
 *
 * Thus, you should know: queue_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param queue Pointer to queue struct
 * @return int64_t -- Popped value, if failed, queue_UNDERFLOW  is returned
 */
int64_t queue_pop (queue que);

/**
 * @brief Peeks to a value in queue and returns it
 *
 * When last element of queue gets popped, consecutive queue_peek calls
 * will return queue_UNDERFLOW.
 *
 * There's no way to be sure that queue_UNDERFLOW value was returned as a
 * result of error, or if that exact number had actually been peeked to
 * from the queue.
 *
 * Thus, you should know: queue_UNDERFLOW = 0x0123456789abcdeful
 *
 * @param queue Pointer to queue struct
 * @return int64_t -- Peeked value, if failed, queue_UNDERFLOW  is returned
 */
int64_t queue_peek (queue que);

/**
 * @brief Prints queue content
 *
 * @param queue Pointer to queue struct
 * @return bool -- false if print failed
 */
bool queue_print (queue que);

/**
 * @brief True if empty
 *
 * @param queue Pointer to queue struct
 * @return bool -- True if empty
 */
bool queue_isempty (queue que);

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
 * @param queue* Reference to the queue, is set to NULL.
 */
void queue_delete (queue *que);

# endif
