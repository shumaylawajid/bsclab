#include <stdio.h>
#include <stdlib.h>

/* AVL Node Structure */
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

/* Helper: Get max of two integers */
int max(a, b) int a, b; {
    return (a > b) ? a : b;
}

/* Helper: Get height of a node */
int getHeight(n) struct Node *n; {
    if (n == NULL) return 0;
    return n->height;
}

/* Helper: Get Balance factor of node N */
int getBalance(n) struct Node *n; {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

/* Create a new node */
struct Node* newNode(key) int key; {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return node;
}

/* RIGHT ROTATE */
struct Node *rightRotate(y) struct Node *y; {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

/* LEFT ROTATE */
struct Node *leftRotate(x) struct Node *x; {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

/* AVL INSERTION with Balancing */
struct Node* insert(node, key) struct Node* node; int key; {
    int balance;

    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    /* Update height */
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    /* Check Balance */
    balance = getBalance(node);

    /* Left Left Case */
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    /* Right Right Case */
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    /* Left Right Case */
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    /* Right Left Case */
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

/* --- TRAVERSAL METHODS --- */

void preOrder(root) struct Node *root; {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(root) struct Node *root; {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void postOrder(root) struct Node *root; {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- AVL TREE MENU ---\n");
        printf("1. Insert Value\n2. Pre-order\n3. In-order\n4. Post-order\n5. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 5) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Pre-order: "); preOrder(root); printf("\n");
                break;
            case 3:
                printf("In-order: "); inOrder(root); printf("\n");
                break;
            case 4:
                printf("Post-order: "); postOrder(root); printf("\n");
                break;
            default:
                printf("Invalid!\n");
        }
    }
    return 0;
}

