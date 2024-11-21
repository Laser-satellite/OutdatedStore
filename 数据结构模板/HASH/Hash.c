#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct hash_table {
    int size;
    int num_elements;
    char** keys;
    int* values;
} HashTable;

HashTable* initHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = TABLE_SIZE;
    table->num_elements = 0;
    table->keys = malloc(table->size * sizeof(char*));
    table->values = malloc(table->size * sizeof(int));

    for (int i = 0; i < table->size; ++i) {
        table->keys[i] = NULL;
        table->values[i] = 0;
    }
    return table;
}

// returns the hash code for the given key
int hash(char* key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); ++i) {
        hash = (hash + key[i]) % TABLE_SIZE;
    }

    return hash;
}

// insert
void put(HashTable* table, char* key, int value) {
    int index = hash(key);
    while (table->keys[index] != NULL && strcmp(table->keys[index], key) != 0) {
        index = (index + 1) % table->size;
    }

    if (table->keys[index] == NULL) {
        table->num_elements++;
    }

    table->keys[index] = key;
    table->values[index] = value;
}

int get(HashTable* table, char* key) {
    int index = hash(key);
    while (table->keys[index] != NULL && strcmp(table->keys[index], key) != 0) {
        index = (index + 1) % table->size;
    }

    if (table->keys[index] == NULL) {
        return -1;
    }

    return table->values[index];
}

void remove_key(HashTable* table, char* key) {
    int index = hash(key);
    while (table->keys[index] != NULL && strcmp(table->keys[index], key) != 0) {
        index = (index + 1) % table->size;
    }

    if (table->keys[index] == NULL) {
        return;
    }
    table->keys[index] = NULL;
    table->values[index] = 0;
    table->num_elements--;
}

// returns the load factor for the hash table
float load_factor(HashTable* table) {
    return (float)table->num_elements / (float)table->size;
}

// returns the number of elements in the hash table
int num_elements(HashTable* table) {
    return table->num_elements;
}

int main() {

    /* e.g. */
    HashTable* table = initHashTable();
    put(table, "Alice", 40);
    put(table, "486", 20);
    printf("%d %d", hash("Alice"), hash("486"));
    printf("%d ", get(table, "486"));
    printf("%d ", num_elements(table));
    printf("%f ", load_factor(table));

    return 0;
}
