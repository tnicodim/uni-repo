/*
Se va introduce urmatoarea secventa de chei numerice intr-un arbore binar ordonat (ABO): 12, -7,
45, 32, 2, 22, 1, 2, 3, 4, 9, 90, 89, 225, 0. Se va respecta ordinea din secventa.
a) sa se determine daca arborele binar ordonat obtinut in urma insertiilor este echilibrat in sens
AVL sau nu.
b) se vor sterge din ABO toate numerele pare si se va afisa rezultatul folosind parcurgerea
inordine.
*/



#include <stdio.h>
#include <math.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node tree[100];
int nextFree = 0;

int getHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + fmax(getHeight(root->left), getHeight(root->right));
}

int isBalanced(struct Node* root) {
    int leftHeight, rightHeight;
    if (root == NULL) {
        return 1;
    }
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return 1;
    }
    return 0;
}

void insert(struct Node* root, int data) {
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = &tree[nextFree++];
            root->left->data = data;
            root->left->left = NULL;
            root->left->right = NULL;
        }
        else {
            insert(root->left, data);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = &tree[nextFree++];
            root->right->data = data;
            root->right->left = NULL;
            root->right->right = NULL;
        }
        else {
            insert(root->right, data);
        }
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int data){
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    tree[nextFree].data = 12;
    tree[nextFree].left = NULL;
    tree[nextFree].right = NULL;
    nextFree++;
    insert(&tree[0], -7);
    insert(&tree[0], 45);
    insert(&tree[0], 32);
    insert(&tree[0], 2);
    insert(&tree[0], 22);
    insert(&tree[0], 1);
    insert(&tree[0], 2);
    insert(&tree[0], 3);
    insert(&tree[0], 4);
    insert(&tree[0], 9);
    insert(&tree[0], 90);
    insert(&tree[0], 89);
    insert(&tree[0], 225);
    insert(&tree[0], 0);
    if (isBalanced(&tree[0])) {
        printf("\nThe tree is balanced\n");
    }
    else {
        printf("\nThe tree is not balanced\n");
    }
    inorder(&tree[0]);
    deleteNode(&tree[0], 12);
    deleteNode(&tree[0], 32);
    deleteNode(&tree[0], 22);
    deleteNode(&tree[0], 2);
    deleteNode(&tree[0], 2);
    deleteNode(&tree[0], 4);
    deleteNode(&tree[0], 90);
    deleteNode(&tree[0], 0);
    printf("\n\n");
    inorder(&tree[0]);

    return 0;
}
