#include <stdio.h>

int stack[100], i, j, choice = 0, n, top = -1;

void push();
void pop();
void peek();
void show();

int main() {
    printf("Enter the maximum number of elements in the stack: ");
    scanf("%d", &n);

    printf("*********Stack operations using array*********\n");
    printf("----------------------------------------------\n");

    while (choice != 5) {
        printf("\nChoose one from the options below...\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Show Elements\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                show();
                break;
            case 5:
                printf("Exiting....\n");
                break;
            default:
                printf("Please enter a valid choice\n");
        }
    }

    return 0;
}

void push() {
    int val;
    if (top == n - 1) {  // Corrected overflow check
        printf("\nOverflow! Stack is full.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
        printf("Value %d pushed into the stack.\n", val);
    }
}

void pop() {
    if (top == -1) {
        printf("\nUnderflow! Stack is empty.\n");
    } else {
        printf("Popped value: %d\n", stack[top]);
        top = top - 1;
    }
}

void show() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack element : %d\n",stack[top]);
    }
}
