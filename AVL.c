#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

int height(struct AVLNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

struct AVLNode *newNode(int key) {
    struct AVLNode *node = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode *rightRotate(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}


struct AVLNode *leftRotate(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;


    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


int getBalance(struct AVLNode *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


struct AVLNode *insert(struct AVLNode *node, int key) {

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;


    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}


void preOrder(struct AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}


struct AVLNode *minValueNode(struct AVLNode *node) {
    struct AVLNode *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct AVLNode *deleteNode(struct AVLNode *root, int key) {

    if (root == NULL)
        return root;


    if (key < root->key)
        root->left = deleteNode(root->left, key);


    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {

        if ((root->left == NULL) || (root->right == NULL)) {
            struct AVLNode *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct AVLNode *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);


    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void printSpaces(int n) {
	int i;
    for (i = 0; i < n; i++)
        printf(" ");
}


void printTree(struct AVLNode *root, int space) {
    if (root == NULL)
        return;

    space += 5;
    printTree(root->right, space);
    printf("\n");
    printSpaces(space);
    printf("%d\n", root->key);
    printTree(root->left, space);
}

int main() {
    struct AVLNode *root = NULL;
    int choice, key;

    do {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Preorder Traversal\n");
        printf("4. Display Tree Structure\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("AVL Tree Structure:\n");
                printTree(root, 0);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice <= 5);

    return 0;
}
