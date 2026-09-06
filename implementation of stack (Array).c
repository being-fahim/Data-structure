#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

void push();
void pop();
void display();

int main() {
    int choice;
    do {
    system("cls");
        printf("\n----------Stack----------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("-------------------------\n");
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
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
        if (choice != 4) {
            while (getchar() != '\n');
            getchar();
        }
    } while (choice != 4);

    return 0;
}

void push() {
    int n;
    if (top == MAXSIZE - 1) {
        printf("\nStack Overflow!\n");
    } else {
        printf("Enter your element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("Successfully pushed %d onto the stack.\n", n);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("\nStack is empty!\n");
    } else {
        printf("\n------Elements of stack------\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void pop() {
    int m;
    if (top == -1) {
        printf("\nStack Underflow (Empty)!\n");
    } else {
        m = stack[top];
        top--;
        printf("\nPopped element: %d\n", m);
    }
}
