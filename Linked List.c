#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void insert(int data, struct node **head) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->value = data;
    newnode->next = *head;
    *head = newnode;
}

void delnode(int data, struct node **head) {
    struct node *curr = *head;
    struct node *prev = NULL;
    
    while (curr != NULL && curr->value == data) {
        *head = curr->next;
        free(curr);
        curr = *head;
    }
    
    while (curr != NULL) {
        while (curr != NULL && curr->value != data) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) return;
        
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
}

void printList(struct node* node) {
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    insert(90, &head);
    insert(18, &head);
    insert(20, &head);
    insert(190, &head);
    
    printf("Original list: ");
    printList(head);
    
    delnode(20, &head);
    
    printf("List after deletion: ");
    printList(head);
    
    return 0;
}

