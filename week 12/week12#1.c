#include <stdio.h>
#include <stdlib.h>

struct Node {// evry leaf or branch in the your tree is a struct node .it contains data : AN INTEGER TO STORE THE VALUE, LEFT POINTER: points to the root of the left subtree(smaller values)
    int data;
    struct Node *left, *right; // right [ointer : points to the root of the right subtree(larger values)
   // pointers to the two children  
};

/* Create a new node */
struct Node* newNode(item)
    int item;
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // allocate memory
    temp->data = item; // set the value
    temp->left = temp->right = NULL; // initialize children as empty....null ensures that the new node starts as a leaf with no children
    return temp;
}

/* SEARCH for a key */
struct Node* search(root, key)
    struct Node* root;
    int key;
{
    if (root == NULL || root->data == key) // base case : found it or empty..
        return root; 
    
    if (root->data < key)   // key is bigger ? go right ....is the bst property in action..we ignore half the tree at every step to find the key quickly 
        return search(root->right, key);

    return search(root->left, key);  // key smaller go right 
}

/* INSERT a new node */
struct Node* insert(node, data)
    struct Node* node;
    int data;
{
    if (node == NULL) return newNode(data);// found an empty spot place node here

    if (data < node->data) // recurse left if smaller 
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);// recurse right if larger ....

    return node;// return the updated pointer
}

/* Find minimum value (helper for delete) */
struct Node* minValueNode(node)
    struct Node* node;
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/* DELETE a node */
struct Node* deleteNode(root, key)
    struct Node* root;
    int key;
{
    struct Node* temp;
    if (root == NULL) return root; // item not found

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {  // CASE 1 & 2: ONE CHILD OR LEAF..
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minValueNode(root->right); // FIND SMALLEST  ON RIGHT 
        root->data = temp->data;  // COPY ITS VALUE TO THE ROOT 
        root->right = deleteNode(root->right, temp->data);  // DELETE THE OLD SUCCESSOR..
    }  // MIN VALUE NODE : used in caswe 3 to find the inorder successor.. it ensures that when we delete a node, the tree stays sorted.
    return root;
}

void inorder(root)
    struct Node* root;
{
    if (root != NULL) {
        inorder(root->left); // step 1:Visit everything smaller (left).
        printf("%d ", root->data); // step 2: Visit the middle(root).
        inorder(root->right); // step 3: Visit everything larger (right).
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. View (Inorder)\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val)) printf("Found!\n");
                else printf("Not Found.\n");
                break;
            case 4:
                printf("BST Inorder: ");
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

