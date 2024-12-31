#include <stdio.h>
#define MAX 5

struct CQueue {
    int items[MAX];
    int front;
    int rear;
};

void initialize(struct CQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(struct CQueue *q) {
    return q->front == -1;
}

void enqueue(struct CQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(struct CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

void display(struct CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    do {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

int main() {
    struct CQueue q;
    initialize(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    
    display(&q);
    
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    
    enqueue(&q, 50);
    enqueue(&q, 60);
    
    display(&q);
    
    return 0;
}