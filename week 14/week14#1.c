#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

/* Linked List Node for Chaining */
struct Node {
    int key;
    int value;
    struct Node* next;
};

/* The Hash Table */
struct HashTable {
    struct Node* buckets[TABLE_SIZE];
};

/* d) HASH FUNCTION */
int hashFunction(key)
    int key;
{
    int h;
    h = key % TABLE_SIZE;
    if (h < 0) h = h + TABLE_SIZE;
    return h;
}

/* Initialize Table */
void initTable(ht)
    struct HashTable* ht;
{
    int i;
    i = 0;
    while (i < TABLE_SIZE) {
        ht->buckets[i] = NULL;
        i++;
    }
}

/* TRAVERSAL: Display all elements */
void traverse(ht)
    struct HashTable* ht;
{
    int i;
    struct Node* current;
    
    printf("\n--- Hash Table Traversal ---\n");
    i = 0;
    while (i < TABLE_SIZE) {
        printf("Bucket [%d]: ", i);
        current = ht->buckets[i];
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
        i++;
    }
}

/* a) INSERTION */
void insert(ht, key, value)
    struct HashTable* ht;
    int key, value;
{
    int index;
    struct Node* current;
    struct Node* newNode;

    index = hashFunction(key);
    current = ht->buckets[index];

    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;
}

/* c) SEARCH */
int search(ht, key)
    struct HashTable* ht;
    int key;
{
    int index;
    struct Node* current;
    index = hashFunction(key);
    current = ht->buckets[index];
    while (current != NULL) {
        if (current->key == key) return current->value;
        current = current->next;
    }
    return -1;
}

/* b) DELETION */
void delete(ht, key)
    struct HashTable* ht;
    int key;
{
    int index;
    struct Node *current, *prev;
    index = hashFunction(key);
    current = ht->buckets[index];
    prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) ht->buckets[index] = current->next;
            else prev->next = current->next;
            free(current);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key %d not found.\n", key);
}

int main() {
    struct HashTable myTable;
    int choice, k, v;

    initTable(&myTable);

    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Traverse 5.Exit: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        if (choice == 1) {
            printf("Key & Value: ");
            scanf("%d %d", &k, &v);
            insert(&myTable, k, v);
        } else if (choice == 2) {
            printf("Key: ");
            scanf("%d", &k);
            delete(&myTable, k);
        } else if (choice == 3) {
            printf("Key: ");
            scanf("%d", &k);
            v = search(&myTable, k);
            if (v != -1) printf("Value: %d\n", v);
            else printf("Not found.\n");
        } else if (choice == 4) {
            traverse(&myTable);
        }
    }
    return 0;
}

