#1.	Discuss the disadvantages of linear queue. 
# Illustrate the implementation of circular queue using C, C++ or Python. [6]

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty())
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear)          // last element removed
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50);
    enqueue(60);        // overflow
    display();
    dequeue(); dequeue();
    enqueue(60); enqueue(70);   // reuses freed slots
    display();
    return 0;
}
