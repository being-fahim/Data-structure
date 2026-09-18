#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *add;
};struct node *start = NULL , *temp, *new1, *prev, *next;

void create();
void insert_first();
void insert_last();
void insert_middle();
void delete_first();
void delete_last();
void delete_middle();
void display();
void search();
void count_node();

int main() {
    int choice;
    do {
    system("cls");
        printf("\n*----------Linked list----------*\n");
        printf(" 1. Create\n 2. Insert on first\n 3. Insert on last \n 4. Insert on Middle\n 5. Delete from First\n 6. Delete from last \n 7. Delete from Middle\n 8. Display\n 9. Search\n10. Count the node\n11. Exit");
        printf("\n*-------------------------------*\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert_first();
                break;
            case 3:
                insert_last();
                break;
            case 4:
                insert_middle();
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_last();
                break;
            case 7:
                delete_middle();
                break;
            case 8:
                display();
                break;
            case 9:
                search();
                break;
            case 10:
                count_node();
            case 11:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
        if (choice != 11) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');
            getchar();
        }
    } while (choice != 11);

    return 0;
}
void create() {
    int n;
    char ch;
    printf("\nEnter an element: ");
    scanf("%d", &n);
    start = (struct node *)(malloc(sizeof(struct node)));
    start -> data = n;
    start -> add = NULL;
    temp = start;

    printf("\nWant to continue?\nAns: ");
    scanf(" %c", &ch);
    while(ch == 'y' || ch == 'Y'){
        printf("\nEnter an element: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = temp -> add;
        printf("\nWant to continue?\nAns: ");
        scanf(" %c", &ch);
    }
}


void insert_first() {
    int n;
    if(start == NULL)
        printf("List not found");
    else{
        printf("Enter a value: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = start;
        start = new1;
    }
}

void insert_last() {
    int n, i = 1;
    if(start == NULL)
        printf("List not found");
    else{
        printf("Enter a value: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        temp = start;
        while(temp -> add != NULL){
            temp = temp -> add;
        }temp -> add = new1;
    }
}

void insert_middle() {
    int n, pos, i = 1;
    if(start == NULL)
        printf("\nList not found");
    else{
        printf("\nEnter a value: ");
        scanf("%d", &n);
        printf("\nIn whice position do you want to store the value: ");
        scanf("%d", &pos);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        next = start;
        while(i < pos){
            prev = next;
            next = next -> add;
            i++;
        }
        prev -> add = new1;
        new1 -> add = next;

    }
}

void delete_first() {
    if(start == NULL)
        printf("List not found");
    else{
        temp = start;
        start = start -> add;
        printf("Deleted element is: %d", temp -> data);
        free(temp);
    }
}

void delete_last() {
    if (start == NULL) {
        printf("List is empty\n");
    }else{
        if (start->add == NULL) {
            printf("Deleted element is: %d\n", start->data);
            free(start);
            start = NULL;
        }

        temp = start;
        while (temp->add != NULL) {
            prev = temp;
            temp = temp->add;
        }
        prev->add = NULL;
        printf("Deleted element is: %d\n", temp->data);
        free(temp);
    }
}

void delete_middle() {
    int pos, i = 1;
    if(start == NULL)
        printf("List not found");
    else{
        printf("\nIn whice position do you want to store the value: ");
        scanf("%d", &pos);

        temp = start;
        while(i < pos){
            prev = temp;
            temp = temp -> add;
            i++;
        }
        next = temp -> add;
        prev -> add = next;
        printf("Deleted element is : %d", temp ->data);
        free(temp);
    }
}


void display() {
    if(start == NULL)
        printf("\nList not found!");
    else{
        temp = start;
        while(temp != NULL){
            printf("\t%d", temp ->data);
            temp = temp ->add;
        }

    }
}

void search(){
    int s, f = 0;
    if(start == NULL)
        printf("\nList not found!");
    else{
        printf("\nEnter the value you are searching: ");
        scanf("%d", &s);
        temp = start;
        while(temp -> data == s){
            f = 1;
            break;
        }
        temp = temp -> add;
    }
    if(f == 1)
        printf("Searching successful");
    else
        printf("Searching failed!");
}

void count_node(){
    int count = 0;
    temp = start;
    while(temp != NULL){
        count++;
        temp = temp -> add;
    }
    printf("Total node is %d", count);
}


