#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void createList(void);
void displayList(void);
void insertAtPos(void);
void deleteAtPos(void);
void clearInput(void);

int main() {
    int choice;
    while (1) {
        printf("\n--- CIRCULAR LIST ---");
        printf("\n1. Create/Add Nodes");
        printf("\n2. Insert by Position");
        printf("\n3. Delete by Position");
        printf("\n4. Display List");
        printf("\n5. Exit\nChoice: ");
        
        if (scanf("%d", &choice) != 1) {
            clearInput();
            continue;
        }

        if (choice == 1) createList();
        else if (choice == 2) insertAtPos();
        else if (choice == 3) deleteAtPos();
        else if (choice == 4) displayList();
        else if (choice == 5) break;
    }
    return 0;
}

void insertAtPos() {
    struct Node *newNode, *temp;
    int val, pos, i;

    printf("Enter position and value: ");
    if (scanf("%d %d", &pos, &val) != 2 || pos < 1) return;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else if (pos == 1) {
        newNode->next = last->next;
        last->next = newNode;
    } else {
        temp = last->next;
        for (i = 1; i < pos - 1 && temp != last; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == last) last = newNode;
    }
}

void deleteAtPos() {
    struct Node *curr, *prev;
    int pos, i;

    if (last == NULL) return;

    printf("Enter position to delete: ");
    if (scanf("%d", &pos) != 1 || pos < 1) return;

    curr = last->next;
    prev = last;

    for (i = 1; i < pos; i++) {
        prev = curr;
        curr = curr->next;
        if (curr == last->next) {
            printf("Position out of bounds.\n");
            return;
        }
    }

    if (curr == last && curr->next == last) {
        last = NULL;
    } else {
        if (curr == last) last = prev;
        prev->next = curr->next;
    }
    
    free(curr);
    printf("Node deleted.\n");
}

void createList() {
    int n, i, val;
    struct Node* newNode;
    printf("How many nodes? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Value: ");
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        if (last == NULL) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
}

void displayList() {
    struct Node* temp;
    if (last == NULL) return;
    temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(head)\n");
}

void clearInput() {
    while (getchar() != '\n');
}

