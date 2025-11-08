#include <stdio.h>
#include <stdlib.h>

int maxsize = 5;
int queue[5];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == maxsize - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;   // first element
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    enqueue(5);
    display();
    return 0;
}
