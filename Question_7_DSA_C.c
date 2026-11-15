#include <stdio.h>
#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % SIZE == front;
}

int isEmpty() {
    return front == -1;
}

// a. Front insertion
void insertFront(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + SIZE) % SIZE;
    dq[front] = x;
    printf("%d inserted at front\n", x);
}

// b. Rear insertion
void insertRear(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    dq[rear] = x;
    printf("%d inserted at rear\n", x);
}

// c. Front deletion
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("%d deleted from front\n", dq[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

// d. Rear deletion
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("%d deleted from rear\n", dq[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + SIZE) % SIZE;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, x;
    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}