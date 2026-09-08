#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int queue[MAXSIZE];
int rear = -1, front = 0;

void insert();
void delete1();
void display();

int main() {
    int choice;
    do {
    system("cls");
        printf("\n----------Queue----------\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete1();
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
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');
            getchar();
        }
    } while (choice != 4);

    return 0;
}

void insert() {
    int n;
    if (rear == MAXSIZE - 1) {
        printf("\nQueue Overflow!\n");
    } else {
        printf("Enter your element: ");
        scanf("%d", &n);
        rear++;
        queue[rear] = n;
        printf("Successfully inserted %d onto the queue.\n", n);
    }
}

void display() {
    int i;
    if (front > rear) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\n------Elements of queue------\n");
        for (i = rear; i >= front; i--) {
            printf("%d\n", queue[i]);
        }
    }
}

void delete1() {
    int m;
    if (front > rear) {
        printf("\nQueue Underflow (Empty)!\n");
    } else {
        m = queue[front];
        front++;
        printf("\nDeleted element: %d\n", m);
    }
}

