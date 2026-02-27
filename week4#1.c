#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* --- I. CREATION --- */
void create() {
    int n, i;
    struct node *newNode, *temp;
    printf("\nHow many nodes do you want to create? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }
    printf("%d nodes created.\n", n);
}

/* --- II. INSERTION --- */
void ins_beg() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void ins_mid() {
    struct node *slow = head, *fast = head, *newNode;
    if (!head) { ins_beg(); return; }

    /* (n-1)/2 logic: stops slow at the left-middle */
    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &newNode->data);
    newNode->next = slow->next;
    slow->next = newNode;
}

void ins_end() {
    struct node *temp = head, *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (!head) { head = newNode; return; }
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

/* --- III. DELETION --- */
void del_beg() {
    struct node *temp = head;
    if (!head) { printf("\nList is Empty!\n"); return; }
    head = head->next;
    free(temp);
    printf("Deleted from beginning.\n");
}

void del_mid() {
    struct node *slow = head, *fast = head, *prev = NULL;
    if (!head) { printf("\nList is Empty!\n"); return; }
    if (!head->next) { free(head); head = NULL; return; }

    /* (n-1)/2 logic: targets node 2 in a 4-node list */
    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (!prev) head = slow->next;
    else prev->next = slow->next;
    free(slow);
    printf("Middle node deleted.\n");
}

void del_end() {
    struct node *temp = head, *prev = NULL;
    if (!head) { printf("\nList is Empty!\n"); return; }
    if (!head->next) { free(head); head = NULL; return; }
    while (temp->next) { prev = temp; temp = temp->next; }
    prev->next = NULL;
    free(temp);
    printf("Deleted from end.\n");
}

/* --- IV. TRAVERSAL --- */
void display() {
    struct node *temp = head;
    if (!head) { printf("\nList is empty.\n"); return; }
    printf("\nList: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* --- MAIN MENU --- */
int main() {
    int ch;
    while (1) {
        printf("\n--- LINKED LIST OPERATIONS ---");
        printf("\n 1. Create List      2. Insert Beg      3. Insert Mid");
        printf("\n 4. Insert End       5. Delete Beg      6. Delete Mid");
        printf("\n 7. Delete End       8. Display List    9. Exit");
        printf("\n Choice: ");
        scanf("%d", &ch);

        if (ch == 1) create();
        else if (ch == 2) ins_beg();
        else if (ch == 3) ins_mid();
        else if (ch == 4) ins_end();
        else if (ch == 5) del_beg();
        else if (ch == 6) del_mid();
        else if (ch == 7) del_end();
        else if (ch == 8) display();
        else if (ch == 9) exit(0);
        else printf("\nInvalid Choice!\n");
    }
    return 0;
}

