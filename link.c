#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} node;


node* start = NULL;


void InsertBegin() {
    node* new1 = (node*)malloc(sizeof(node));
    if (new1 == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("\nEnter value:\n");
    scanf("%d", &new1->data);
    if (start == NULL) {
        start = new1;
        new1->link = NULL;
    } else {
        new1->link = start;
        start = new1;
    }
}


void InsertPosition() {
    node* new1 = (node*)malloc(sizeof(node));
    if (new1 == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("\nEnter value:\n");
    scanf("%d", &new1->data);

    if (start == NULL) {
        start = new1;
        new1->link = NULL;
        return;
    }

    int i = 1, pos;
    node* temp = start;
    printf("\nEnter position:\n");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    while (temp != NULL && i < pos - 1) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    new1->link = temp->link;
    temp->link = new1;
}


void InsertEnd() {
    node* new1 = (node*)malloc(sizeof(node));
    if (new1 == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("\nEnter value:\n");
    scanf("%d", &new1->data);

    if (start == NULL) {
        start = new1;
        new1->link = NULL;
        return;
    }

    node* temp = start;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new1;
    new1->link = NULL;
}


void display() {
    if (start == NULL) {
        printf("\nLinked List is Empty.\n");
        return;
    }

    node* temp = start;
    printf("\nElements in Linked List: \n");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {

    int choice;
    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at a Position\n");
        printf("3. Insert at End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                InsertBegin();
                break;
            case 2:
                InsertPosition();
                break;
            case 3:
                InsertEnd();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
