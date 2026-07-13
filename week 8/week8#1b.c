//b. Linked List (Pointer)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; } *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) return;
    temp->data = val; temp->next = NULL;
    if (!rear) front = rear = temp;
    else { rear->next = temp; rear = temp; }
}

void dequeue() {
    if (!front) { printf("Empty\n"); return; }
    struct Node* temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;
    if (!front) rear = NULL;
    free(temp);
}

void display() {
    struct Node* temp = front;
    while (temp) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
    	printf("menu bar---");
        printf("\n1.Enq \n 2.Deq \n3.Disp \n4.Exit: ");
        printf("\nchoice:");
        scanf("%d", &choice);
        if (choice == 1) { printf("Val: "); scanf("%d", &val); enqueue(val); }
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) break;
    }
    return 0;
}

