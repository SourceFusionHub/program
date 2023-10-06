#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS 4

struct KeyValue {
    int key;
    int value;
};

struct BTreeNode {
    int num_keys;
    bool is_leaf;
    struct KeyValue keys[MAX_KEYS];
    struct BTreeNode* children[MAX_KEYS + 1];
};

struct BTreeNode* create_node() {
    struct BTreeNode* new_node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    new_node->num_keys = 0;
    new_node->is_leaf = true;
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

int binary_search(struct KeyValue arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].key == key) {
            return mid;
        }
        if (arr[mid].key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

struct BTreeNode* insert(struct BTreeNode* root, struct KeyValue key_value) {
    if (root == NULL) {
        struct BTreeNode* new_root = create_node();
        new_root->keys[0] = key_value;
        new_root->num_keys = 1;
        return new_root;
    }

    int idx = binary_search(root->keys, root->num_keys, key_value.key);
    if (idx >= 0) {
        root->keys[idx].value = key_value.value;
    } else {
        int i = root->num_keys - 1;
        if (root->is_leaf) {
            while (i >= 0 && key_value.key < root->keys[i].key) {
                root->keys[i + 1] = root->keys[i];
                i--;
            }
            root->keys[i + 1] = key_value;
            root->num_keys++;
        } else {
            while (i >= 0 && key_value.key < root->keys[i].key) {
                i--;
            }
            i++;
            if (root->children[i]->num_keys == MAX_KEYS) {
                root->children[i] = insert(root->children[i], key_value);
            } else {
                root->children[i] = insert(root->children[i], key_value);
            }
        }
    }

    return root;
}

struct KeyValue* search(struct BTreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    int idx = binary_search(root->keys, root->num_keys, key);
    if (idx >= 0) {
        return &(root->keys[idx]);
    } else if (root->is_leaf) {
        return NULL;
    } else {
        int i = 0;
        while (i < root->num_keys && key > root->keys[i].key) {
            i++;
        }
        return search(root->children[i], key);
    }
}

void print_tree(struct BTreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->num_keys; i++) {
            printf("(%d, %d) ", root->keys[i].key, root->keys[i].value);
        }
        printf("\n");

        if (!root->is_leaf) {
            for (int i = 0; i <= root->num_keys; i++) {
                print_tree(root->children[i]);
            }
        }
    }
}

int main() {
    struct BTreeNode* root = NULL;

    struct KeyValue key_values[] = {{3, 30}, {7, 70}, {2, 20}, {1, 10}, {6, 60}, {8, 80}, {5, 50}, {4, 40}};

    for (int i = 0; i < sizeof(key_values) / sizeof(key_values[0]); i++) {
        root = insert(root, key_values[i]);
    }

    printf("B-tree contents:\n");
    print_tree(root);

    int search_key = 7;
    struct KeyValue* result = search(root, search_key);
    if (result != NULL) {
        printf("Found key %d with value %d\n", search_key, result->value);
    } else {
        printf("Key %d not found\n", search_key);
    }

    return 0;
}
