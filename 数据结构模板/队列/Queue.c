#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
    int head; // idx
    int tail; // idx
} Queue;

void initQueue(Queue* queue) {
    queue->head = 0;
    queue->tail = 0;
}

int isEmpty(Queue* queue) {
    return queue->head == queue->tail;
}

int isFull(Queue* queue) {
    return queue->head = QUEUE_SIZE;
}

void enqueue(Queue* queue, int x) {
    if (isFull(queue)) {
        printf("Error: queue is full.\n");
        return;
    }
    queue->data[queue->tail] = x;
    queue->tail++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: queue is empty.\n");
        return -1;
    }
    int x = queue->data[queue->head];
    queue->head++;
    return x;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: queue is empty.\n");
        return -1;
    }
    return queue->data[queue->head];
}

void remove(Queue* queue, int x) {
    int i;
    for (i = queue->head; i < queue->tail; i++) {
        if (queue->data[i] == x) {
            break;
        }
    }

    if (i == queue->tail) {
        return;
    }

    int j;
    for (j = i; j < queue->tail - 1; j++) {
        queue->data[j] = queue->data[j + 1];
    }
    queue->tail--;
}

int main() {
    /*  Test  */

    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    remove(&q, 2);

    printf("%d ", dequeue(&q));
}