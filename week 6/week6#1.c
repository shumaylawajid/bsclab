#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Global pointer to the last node for O(1) insertions */
struct Node* last = NULL;

/* Function Prototypes */
void createList(void);
void displayList(void);
void deleteNode(void);
void clearInput(void);

int main() {
    int choice;
    while (1) {
        printf("\n--- CIRCULAR LIST ---");
        printf("\n1. Create/Add Multiple Nodes");
        printf("\n2. Delete a Node");
        printf("\n3. Display List");
        printf("\n4. Exit");
        printf("\nChoice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Use numbers.\n");
            clearInput();
            continue;
        }

        if (choice == 1) createList();
        else if (choice == 2) deleteNode();
        else if (choice == 3) displayList();
        else if (choice == 4) break;
        else printf("Invalid option.\n");
    }
    return 0;
}

/* Operation: Create/Insert Multiple Nodes at Once */
void createList() {
    int n, i, val;
    struct Node* newNode;

    printf("How many nodes to add? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Enter a positive integer.\n");
        clearInput();
        return;
    }

    for (i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;

        if (last == NULL) {
            newNode->next = newNode; /* Points to itself */
            last = newNode;
        } else {
            newNode->next = last->next; /* New node points to head */
            last->next = newNode;       /* Old last points to new node */
            last = newNode;             /* Update last */
        }
    }
    printf("Successfully added %d nodes.\n", n);
}

/* Operation: Deletion */
void deleteNode() {
    struct Node *curr, *prev;
    int key;
    if (last == NULL) {
        printf("Empty list.\n");
        return;
    }
    printf("Value to delete: ");
    scanf("%d", &key);
    curr = last->next;
    prev = last;
    do {
        if (curr->data == key) {
            if (curr == last && curr->next == last) last = NULL;
            else {
                if (curr == last) last = prev;
                prev->next = curr->next;
            }
            free(curr);
            printf("Deleted %d\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);
    printf("Value not found.\n");
}

/* Operation: Traversal */
void displayList() {
    struct Node* temp;
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = last->next;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(head)\n");
}

void clearInput() {
    while (getchar() != '\n');
}

