#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

struct RBNode {
    int key;
    Color color;
    struct RBNode *left, *right, *parent;
};

struct RBNode *root = NULL;

// Function to create a new Red-Black Tree node
struct RBNode *newRBNode(int key) {
    struct RBNode *node = (struct RBNode *)malloc(sizeof(struct RBNode));
    node->key = key;
    node->color = RED; // New nodes are red by default
    node->left = node->right = node->parent = NULL;
    return node;
}

// Left rotate subtree rooted with x
void leftRotate(struct RBNode *x) {
    struct RBNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
        
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
        
    y->left = x;
    x->parent = y;
}

// Right rotate subtree rooted with y
void rightRotate(struct RBNode *y) {
    struct RBNode *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
        
    x->parent = y->parent;
    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
        
    x->right = y;
    y->parent = x;
}

// Fix red-black tree violations after insertion
void fixViolation(struct RBNode *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct RBNode *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            struct RBNode *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

// Insert a new node with given key
void insert(int key) {
    struct RBNode *node = newRBNode(key);
    struct RBNode *y = NULL;
    struct RBNode *x = root;

    while (x != NULL) {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else if (node->key > x->key)
            x = x->right;
        else {
            // Duplicate keys not allowed
            printf("Key %d already exists in the tree.\n", key);
            free(node);
            return;
        }
    }

    node->parent = y;

    if (y == NULL) {
        root = node;
    } else if (node->key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }

    fixViolation(node);
}

// Find the node with minimum key in subtree rooted at node
struct RBNode *minValueNode(struct RBNode *node) {
    struct RBNode *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Replace subtree u with subtree v
void transplant(struct RBNode *u, struct RBNode *v) {
    if (u->parent == NULL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}

// Fix violations after deletion
void fixDelete(struct RBNode *x) {
    while (x != root && (x == NULL || x->color == BLACK)) {
        if (x == x->parent->left) {
            struct RBNode *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left == NULL || w->left->color == BLACK) && 
                (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == NULL || w->right->color == BLACK) {
                    if (w->left != NULL)
                        w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right != NULL)
                    w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            struct RBNode *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == NULL || w->right->color == BLACK) &&
                (w->left == NULL || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == NULL || w->left->color == BLACK) {
                    if (w->right != NULL)
                        w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left != NULL)
                    w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if (x != NULL)
        x->color = BLACK;
}

// Deletes a node with given key
void deleteNode(int key) {
    struct RBNode *z = root;
    while (z != NULL) {
        if (z->key == key)
            break;
        else if (key < z->key)
            z = z->left;
        else
            z = z->right;
    }

    if (z == NULL) {
        printf("Key %d not found in the tree.\n", key);
        return;
    }

    struct RBNode *y = z;
    Color y_original_color = y->color;
    struct RBNode *x;

    if (z->left == NULL) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minValueNode(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x != NULL)
                x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            if (y->right != NULL)
                y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        if (y->left != NULL)
            y->left->parent = y;
        y->color = z->color;
    }
    free(z);

    if (y_original_color == BLACK)
        fixDelete(x);
}

// Inorder traversal for displaying the tree keys in ascending order
void inorder(struct RBNode *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d (%s)  ", node->key, node->color == RED ? "R" : "B");
        inorder(node->right);
    }
}

// Helper function to print spaces
void printSpaces(int count) {
	int i;
    for (i = 0; i < count; i++)
        printf(" ");
}

// Print tree structure rotated 90 degrees counterclockwise
void printTree(struct RBNode *root, int space) {
    if (root == NULL)
        return;
    space += 6;
    printTree(root->right, space);
    printf("\n");
    printSpaces(space - 6);
    printf("%d(%s)\n", root->key, root->color == RED ? "R" : "B");
    printTree(root->left, space);
}

int main() {
    int choice, key;
    do {
        printf("\nRed-Black Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Inorder Traversal\n");
        printf("4. Display Tree Structure\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // Invalid input handling
            while (getchar() != '\n'); // clear input buffer
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                if (scanf("%d", &key) == 1) {
                    insert(key);
                    printf("Inserted %d into the tree.\n", key);
                } else {
                    printf("Invalid input! Key must be an integer.\n");
                    while (getchar() != '\n');
                }
                break;
            case 2:
                printf("Enter key to delete: ");
                if (scanf("%d", &key) == 1) {
                    deleteNode(key);
                } else {
                    printf("Invalid input! Key must be an integer.\n");
                    while (getchar() != '\n');
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Red-Black Tree Structure:\n");
                    printTree(root, 0);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}


