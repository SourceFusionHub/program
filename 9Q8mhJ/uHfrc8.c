#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to perform a right rotation
struct Node *rightRotate(struct Node *x) {
    struct Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to perform a left rotation
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Function to splay a given key in the tree
struct Node *splay(struct Node *root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key is in the left subtree
    if (key < root->key) {
        // Key is not in the tree; we're done
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key is in the right subtree
    else {
        // Key is not in the tree; we're done
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Function to insert a new node with a given key in the tree
struct Node *insert(struct Node *root, int key) {
    if (root == NULL)
        return newNode(key);

    // Splay the tree to bring the key to the root
    root = splay(root, key);

    // If key is already present, return the root
    if (root->key == key)
        return root;

    // Otherwise, allocate a new node
    struct Node *newNode = newNode(key);

    // If the key is greater than the root's key, assign the new node's left child as the current root
    if (root->key < key) {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }
    // If the key is smaller than the root's key, assign the new node's right child as the current root
    else {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    }

    return newNode;
}

// Function to perform an inorder traversal of the tree
void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to free the memory allocated for the tree nodes
void freeTree(struct Node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

    printf("Inorder traversal of the splay tree: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
