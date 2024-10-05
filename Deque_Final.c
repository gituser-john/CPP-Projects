#include<stdio.h>
#define MAX 5

int Deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return front == 0 && rear == MAX - 1;
}

void Peek() {
    if(isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("The value at front is %d\n", Deque[front]);
}

void Enqueue_Front(int n) {
    if(isFull() || front == 0) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) {  // If the queue is empty
        front = rear = 0;
    } else {
        front--;
    }
    Deque[front] = n;
    printf("Value %d is Enqueued at front\n", n);
}

void Enqueue_Rear(int n) {
    if(isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) {  // If the queue is empty
        front = rear = 0;
    } else {
        rear++;
    }
    Deque[rear] = n;
    printf("Value %d is Enqueued at rear\n", n);
}

void Dequeue_Front() {
    if(isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("The value %d is dequeued from front\n", Deque[front]);
    if(front == rear) {  // Single element was in queue
        front = rear = -1;
    } else {
        front++;
    }
}

void Dequeue_Rear() {
    if(isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("The value %d is dequeued from rear\n", Deque[rear]);
    if(front == rear) {  // Single element was in queue
        front = rear = -1;
    } else {
        rear--;
    }
}

void Display() {
    if(isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("The Queue is : ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", Deque[i]);
    }
    printf("\n"); 
}

int main() {
    int n, m;
    do {
        printf("Enter \n1.Enqueue at front\n2.Enqueue at rear\n3.Dequeue from front\n4.Dequeue from rear\n5.Peek\n6.Display\n7.isEmpty\n8.isFull\n9.Exit\n");
        scanf("%d", &n);
        switch(n) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &m);
                Enqueue_Front(m);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &m);
                Enqueue_Rear(m);
                break;
            case 3:
                Dequeue_Front();
                break;
            case 4:
                Dequeue_Rear();
                break;
            case 5:
                Peek();
                break;
            case 6:
                Display();
                break;
            case 7:
                printf("Queue is %s\n", isEmpty() ? "Empty" : "Not Empty");
                break;
            case 8:
                printf("Queue is %s\n", isFull() ? "Full" : "Not Full");
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please enter a number between 1 and 9.\n");
        }
    } while(n != 9);

    return 0;
}