#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
int moves = 0;

void insert(int value, int position) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
        moves = 1;
    }
    else {
        struct node* current_node = head;
        for (int i = 1; i < position - 1 && current_node != NULL; i++) {
            current_node = current_node->next;
            moves++;
        }
        if (current_node != NULL) {
            new_node->next = current_node->next;
            current_node->next = new_node;
            moves++;
        }
    }
}

void delete(int position) {
    if (head == NULL) return;
    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        moves = 1;
    }
    else {
        struct node* current_node = head;
        for (int i = 1; i < position - 1 && current_node != NULL; i++) {
            current_node = current_node->next;
            moves++;
        }
        if (current_node != NULL && current_node->next != NULL) {
            struct node* temp = current_node->next;
            current_node->next = current_node->next->next;
            free(temp);
            moves++;
        }
    }
}

void display() {
    struct node* current_node = head;
    printf("List: ");
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("Menu:\n");
        printf("(1) Insert\n");
        printf("(2) Delete\n");
        printf("(3) Display list\n");
        printf("(0) Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);
            insert(value, position);
            printf("Number of moves: %d\n", moves);
            break;
        case 2:
            printf("Enter the position to delete from: ");
            scanf("%d", &position);
            delete(position);
            printf("Number of moves: %d\n", moves);
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
