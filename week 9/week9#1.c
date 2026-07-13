// C PROGRAMS THAT IMPLEMENTS & DEMONSTRATES WORKING OF C .QUEUE
#include <stdio.h>
#define N 25

struct cqtype {
    int q[N];
    int front, rear;
};

typedef struct cqtype cqueue;

int isempty(int front) {
    if (front == -1) 
        return 1;
    else
        return 0;
}

int isfull(int front, int rear) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
        return 1;
    else 
        return 0;
}

void cqinsert(cqueue *p, int item) {
    // Fixed mismatched parentheses here
    if ((p->front == 0 && p->rear == N - 1) || (p->front == p->rear + 1)) {
        printf("circular queue full - insertion not possible\n");
        return;
    }
    
    if (p->rear == -1)
        p->rear = p->front = 0;
    else if (p->rear == N - 1)
        p->rear = 0;
    else
        (p->rear)++;
        
    p->q[p->rear] = item;
}

int cqdelete(cqueue *p) {
    int item;
    if (p->front == -1) {
        printf("Circular Queue empty-Deletion not possible\n");
        return 0;
    }
    
    item = p->q[p->front];
    if (p->front == p->rear)
        p->front = p->rear = -1;
    else if (p->front == N - 1)
        p->front = 0;
    else
        (p->front)++;
        
    return item;
}

void traversal(cqueue cq) {
    int i;
    if (cq.front == -1) {
        printf("\nCircular Queue empty\n");
        return;
    }
    
    printf("\nContents of Circular Queue:\n");
    if (cq.front <= cq.rear) {
        for (i = cq.front; i <= cq.rear; i++)
            printf("%d ", cq.q[i]); // Added space for readability
    } else {
        for (i = cq.front; i <= N - 1; i++)
            printf("%d ", cq.q[i]); // Added space for readability
        for (i = 0; i <= cq.rear; i++)
            printf("%d ", cq.q[i]); // Added space for readability
    }
    printf("\n");
}

int main() {
    int choice, item;
    cqueue cq;
    cq.front = cq.rear = -1;
    
    do {
        printf("\n MENU(CIRCULAR QUEUE OPERATIONS):");
        printf("\n1.insert\n2.delete\n3.traversal\n4.exit\n");
        printf("choice?");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                printf("Enter an int value to be inserted:");
                scanf("%d", &item);
                cqinsert(&cq, item);
                break;
                
            case 2: 
                if (isempty(cq.front)) {
                    printf("\n Circular Queue empty\n");
                } else {
                    item = cqdelete(&cq);
                    printf("item deleted :%d\n", item);
                }
                break;
                
            case 3:
                traversal(cq);
                break;
        }
    } while (choice != 4);
    
    return 0;
}
