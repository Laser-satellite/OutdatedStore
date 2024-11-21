#include<stdio.h>
#include<stdlib.h>

typedef int T;
typedef struct node {
    T data;
    struct node* next;
} Node;

Node* newNode(T data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertFirst(Node** head, T data) {
    Node* new_node = newNode(data);
    new_node->next = *head;
    *head = new_node;
}

void insertLast(Node** head, T data) {
    Node* new_node = newNode(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

T removeData(Node** head, T data) {
    Node* current = *head;
    Node* previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            return data;
        }
        previous = current;
        current = current->next;
    }
}

void view(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void clear(Node* root) {
    if (root == NULL) {
        return;
    } else {
        clear(root->next);
        free(root);
    }
}

int main() {
    /* TEST */
    Node* head = NULL;
    insertLast(&head, 1);
    insertFirst(&head, 2);
    insertLast(&head, 3);

    view(head);

    removeData(&head, 4);
    removeData(&head, 2);

    view(head);

    clear(head);
}