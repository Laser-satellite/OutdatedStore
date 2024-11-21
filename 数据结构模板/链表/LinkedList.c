#include <stdio.h>
#include <stdlib.h>

typedef int Object; // ×Ô¼º¸Ä

typedef struct node {
    Object data;
    struct node* next;
} Node;

typedef struct linkedList {
    int size;
    Node* head;
} LinkedList;

LinkedList* initList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;

    return list;
}

int size(LinkedList* list) {
    return list->size;
}

int isEmpty(LinkedList* list) {
    return list->size == 0;
}

void addFirst(LinkedList* list, Object element) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->next = list->head;
    list->head = node;
    list->size++;
}

Object removeFirst(LinkedList* list) {
    if (isEmpty(list)) {
        printf("Error: cannot remove from an empty list.\n");
        exit(1);
    }
    Node* old_node = list->head;
    if (old_node->next != NULL) {
        list->head = old_node->next;
    }
    list->size--;
    if (list->size == 0) {
        list->head = NULL;
    }
    Object element = old_node->data;
    free(old_node);
    return element;
}

Object getFirst(LinkedList* list) {
    if (isEmpty(list)) {
        printf("Error: Cannot get from an empty list.\n");
        exit(1);
    }
    return list->head->data;
}

void add(LinkedList* list, int index, Object element) {
    if (index < 0 || index > list->size) {
        printf("Error: Index out of range!\n");
        exit(1);
    }
    if (index == 0) {
        addFirst(list, element);
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;

    Node* current = list->head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
}

Object removeAt(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: cannot remove from an empty list.\n");
        exit(1);
    }

    if (index == 0) {
        return removeFirst(list);
    }

    Node* current = list->head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    Node* old_node = current->next;
    current->next = old_node->next;
    Object element = old_node->data;
    list->size--;
    free(old_node);
    return element;
}

Object get(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: cannot get from an empty list.\n");
        exit(1);
    }
    Node* current = list->head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

void clear(LinkedList* list) {
    while (!isEmpty(list)) {
        removeFirst(list);
    }
}

int main() {

    /* test e.g. */
    LinkedList* list = initList();
    add(list, 0, 8);
    addFirst(list, 9);
    add(list, 2, 7);

    for (Node* current = list->head; current != NULL; current = current->next) {
        printf("%d ", (int)current->data);
    }

    removeAt(list, 1);
    removeFirst(list);
    removeAt(list, 0);
    
    for (Node* current = list->head; current != NULL; current = current->next) {
        printf("%d ", (int)current->data);
    }

    clear(list);
    free(list);

    return 0;
}