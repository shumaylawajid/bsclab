//Write a C program that implements Queue and its operations using 
//a. Arrays 
#include <stdio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) printf("Queue Overflow!\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
        printf("Inserted %d\n", val);
    }
}

void dequeue() {
    if (front == -1 || front > rear) printf("Queue Underflow!\n");
    else {
        printf("Deleted: %d\n", queue[front++]);
        if (front > rear) front = rear = -1;
    }
}

void display() {
    int i;
    if (front == -1) printf("Empty\n");
    else {
        for (i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
    	printf("menu bar--");
        printf("\n1.Enq \n2.Deq \n3.Disp \n4.Exit ");
        printf("\nchoice:");
        scanf("%d", &choice);
        if (choice == 1) { printf("Val: "); scanf("%d", &val); enqueue(val); }
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) break;
    }
    return 0;
}

