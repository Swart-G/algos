#ifndef ALGOS_QUEUE_H
#define ALGOS_QUEUE_H

typedef struct QueueNode {
    int value;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *head;
    QueueNode *tail;
} Queue;

Queue *queue_create(void);
int queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue, int *value);
int queue_front(Queue *queue, int *value);
int queue_is_empty(Queue *queue);
int queue_destroy(Queue *queue);
int queue_print(Queue *queue);

#endif // ALGOS_QUEUE_H
