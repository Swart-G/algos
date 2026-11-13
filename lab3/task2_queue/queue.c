#include "queue.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

Queue *queue_create(void) {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int queue_enqueue(Queue *queue, int value) {
    if (queue == NULL) {
        return -EINVAL;
    }

    QueueNode *new_node = malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        return -ENOMEM;
    }

    new_node->value = value;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
    } else {
        queue->tail->next = new_node;
    }
    queue->tail = new_node;

    return 0;
}

int queue_dequeue(Queue *queue, int *value) {
    if (queue == NULL) {
        return -EINVAL;
    }
    if (queue->head == NULL) {
        return -ENOENT;
    }

    QueueNode *old_head = queue->head;

    if (value != NULL) {
        *value = queue->head->value;
    }
    queue->head = queue->head->next;

    if (queue->tail == old_head) {
        queue->tail = queue->head;
    }

    free(old_head);
    return 0;
}

// 1 при FALSE, 0 при TRUE
int queue_is_empty(Queue *queue) {
    if (queue == NULL || queue->head == NULL) {
        return 1;
    }

    return 0;
}

int queue_front(Queue *queue, int *value) {
    if (queue == NULL || value == NULL) {
        return -EINVAL;
    }
    if (queue->head == NULL) {
        return -ENOENT;
    }

    *value = queue->head->value;
    return 0;
}

int queue_destroy(Queue *queue) {
    if (queue == NULL) {
        return -EINVAL;
    }

    while (queue_is_empty(queue) == 0) {
        queue_dequeue(queue, NULL);
    }
    free(queue);
    return 0;
}

int queue_print(Queue *queue) {
    if (queue == NULL) {
        return -EINVAL;
    }

    QueueNode *current_node = queue->head;
    printf("Элементы очереди:\n");
    while (current_node != NULL) {
        printf("%d\n", current_node->value);
        current_node = current_node->next;
    }
    printf("Конец очереди.\n");
    return 0;
}