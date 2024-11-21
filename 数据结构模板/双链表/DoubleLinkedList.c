#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int Object; // Changable.

typedef struct node {
    Object data;
    struct node* prev;
    struct node* next;
} Node;

typedef struct doubly_linked_list {
    int size;
    Node* head;
    Node* tail;
} DoublyLinkedList;

DoublyLinkedList* initList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int size(DoublyLinkedList* list) {
    return list->size;
}

int isEmpty(DoublyLinkedList* list) {
    return list->size == 0;
}

void addFirst(DoublyLinkedList* list, Object element) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;
    new_node->prev = NULL;
    new_node->next = list->head;
    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

Object removeFirst(DoublyLinkedList* list) {
    if (isEmpty(list)) {
        printf("Error: Cannot remove from an empty list.\n");
        exit(1);
    }

    Object element = list->head->data;
    Node* old_head = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    }
    free(old_head);
    list->size--;
    if (isEmpty(list)) {
        list->tail = NULL;
    }
    return element;
}

Object getFirst(DoublyLinkedList* list) {
    if (isEmpty(list)) {
        printf("Error: Cannot get from an emty list.\n");
        exit(1);
    }
    return list->head->data;
}

void addLast(DoublyLinkedList* list, Object element) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
    list->size++;
}

Object removeLast(DoublyLinkedList* list) {
    if (isEmpty(list)) {
        printf("Error: Cannot remove from an empty list.\n");
        exit(1);
    }

    Object element = list->tail->data;
    Node* old_node = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    }
    free(old_node);
    list->size--;
    if (isEmpty(list)) {
        list->head = NULL;
    }
    return element;
}

Object getLast(DoublyLinkedList* list) {
    if (isEmpty(list)) {
        printf("Error: Cannot get from an emty list.\n");
        exit(1);
    }
    return list->tail->data;
}

Object get(DoublyLinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of range.\n");
        exit(1);
    }

    Node* current;
    if (index < list->size / 2) {
        current = list->head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        current = list->tail;
        for (int i = list->size - 1; i > index; --i) {
            current = current->prev;
        }
    }
    return current->data;
}

Object set(DoublyLinkedList* list, int index, Object element) {
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of range.\n");
        exit(1);
    }

    Node* current;
    if (index < list->size / 2) {
        current = list->head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
    }
    else {
        current = list->tail;
        for (int i = list->size - 1; i > index; --i) {
            current = current->prev;
        }
    }
    Object old_element =  current->data;
    current->data = element;
    return old_element;
}

void add(DoublyLinkedList* list, int index, Object element) {
    if (index < 0 || index > list->size) {
        printf("Error: Index out of range.\n");
        exit(1);
    }
    if (index == 0) {
        addFirst(list, element);
    } else if (index == list->size) {
        addLast(list, element);
    }
    else {
        Node* current;
        if (index < list->size / 2) {
            current = list->head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
        }
        else {
            current = list->tail;
            for (int i = list->size - 1; i > index; --i) {
                current = current->prev;
            }
        }

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = element;
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
        list->size++;
    }
}

Object removeAt(DoublyLinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of range.\n");
        exit(1);
    }
    if (index == 0) {
        return removeFirst(list);
    }
    else if (index == list->size - 1) {
        return removeLast(list);
    }
    else {
        Node* current;
        if (index < list->size / 2) {
            current = list->head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
        }
        else {
            current = list->tail;
            for (int i = list->size - 1; i > index; --i) {
                current = current->prev;
            }
        }

        Object element = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        list->size--;

        return element;
    }
}

void clear(DoublyLinkedList* list) {
    while (!isEmpty(list)) {
        removeLast(list);
    }
}

int main(int argc, char const* argv[]) {
    /* ²âÊÔÑùÀý */

    DoublyLinkedList* list = initList();
    addFirst(list, 9);
    addLast(list, 7);
    add(list, 1, 8);
    
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", (int)current->data);
        current = current->next;
    }

    printf("%d ", removeAt(list, 2));
    printf("%d ", removeFirst(list));
    printf("%d ", removeLast(list));

    return 0;
}