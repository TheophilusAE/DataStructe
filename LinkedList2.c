Xyno
viner2767
Invisible

Oditya — 17/02/2024 08:26
Source Code Sesi 1 :
https://amenable-frill-768.notion.site/Struct-Of-Array-Session-1-ec13dceda6e34a87a1652ab3cbcd1cd0?pvs=4
Odit's Notion on Notion
Struct Of Array (Session 1) | Notion
//Include Library
#include
#include
#include
#include

//Define Size
#define size 3

//Deklarasi Struct
struct Barang
{
char idItem[6];
int stock;
};

//Prototype Function
void view(struct Barang *ptr);
void sell(struct Barang *ptr);
void add(struct Barang *ptr);


//Function Utama
int main()
{
//Deklarasi Barang
struct Baran...
Struct Of Array (Session 1) | Notion
zaloeskr — 24/02/2024 08:45
insert awal akhir_delete awal

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{

int data;
struct Node *next;
};

struct Node insertAtBeginning(struct Node head, int data){
struct Node newNode = (struct Node)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = head;
return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data){
struct Node newNode = (struct Node)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;

if(head == NULL){
return newNode;
}

struct Node* temp = head;
while(temp->next != NULL){
temp = temp->next;
}

temp->next = newNode;
return head;
}

struct Node* deleteBegin(struct Node* head){
if(head == NULL){
printf("Linked List Kodong");
return NULL;
}

struct Node* temp = head;
head = head->next;
free(temp);
return head;

}
void display(struct Node* head){
while(head != NULL){
printf("%d -> ", head->data);
head = head->next;
}
printf("NULL\n");
}

int main(){

struct Node *head = NULL;
int input, data;

while(1){

printf("\n\nMenu\n");
printf("1. Insert Begin\n");
printf("2. Insert End\n");
printf("3. Delete Begin\n");
printf("4. Display data\n");
printf("5. Exit\n");
printf("input : ");
scanf("%d", &input);

switch(input){
case 1: 
printf("Masukin data : ");
scanf("%d", &data);
head = insertAtBeginning(head, data);
break;
case 2: 
printf("Masukin data : ");
scanf("%d", &data);
head = insertAtEnd(head, data);
break;
case 3: 
head = deleteBegin(head);
break;
case 4: 
printf("Linked List : ");
display(head);
break;
case 5: 
exit(0);
break;
default:
printf("Input Invalid");
}
}

return 0;
... (1 line left)
Collapse
Sesi_2_SLL.txt
2 KB
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menampilkan isi linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk menambahkan node di awal linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi Memori Gagal.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Fungsi untuk menambahkan node di tengah linked list
void insertInMiddle(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi Memori Gagal.\n");
        exit(1);
    }
    newNode->data = data;
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Posisi invalid.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk menambahkan node di akhir linked list
void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Fungsi untuk menghapus node di awal linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Linked list Kosong.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Fungsi untuk menghapus node di akhir linked list
void deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Linked list Kosong.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prevNode = NULL;
    while (temp->next != NULL) {
        prevNode = temp;
        temp = temp->next;
    }
    if (prevNode != NULL) {
        prevNode->next = NULL;
... (59 lines left)
Collapse
Singly_Linked_List.txt
5 KB
Oditya — 02/03/2024 08:48
Source Code Sesi 3 :
https://amenable-frill-768.notion.site/Double-Linked-List-Session-3-30379ee44178430dbab58f0ea133544d?pvs=4 
Odit's Notion on Notion
Double Linked List (Session 3) | Notion
//Deklarasi Library
#include
#include
#include

//Deklarasi Tipe Variabel Struct
struct Node
{
//data
int data;

//struct pointer
struct Node *next;
struct Node *prev;
};

//Fungsi masukkan data dari depan
void insertHead(struct Node **head, struct Node **tail, int data)
{
struct Node *newNode = (struct Node*)malloc(si...
Double Linked List (Session 3) | Notion
zaloeskr — 09/03/2024 08:46
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define M 7
Expand
Hashing_SourceCode.txt
2 KB
Oditya — 16/03/2024 08:31
Source Code Sesi 5 :
https://amenable-frill-768.notion.site/Binary-Search-Tree-eb5a59de3a5648f791d8cfe3e76dcafe?pvs=4
Odit's Notion on Notion
Binary Search Tree | Notion
#include
#include
#include

// Struct Binary Tree
struct Node
{
int data;
struct Node *right;
struct Node *left;
};

// Membuat Node baru
void newNode(struct Node **ptr, int data)
{
*ptr = (struct Node *)malloc(sizeof(struct Node));
(*ptr)->data = data;
(*ptr)->left = NULL;
(*ptr)->right = NULL;
}

// Menyisipkan d...
Binary Search Tree | Notion
zaloeskr — 07/05/2024 11:18
@everyone Untuk Modul Sesi 8 kemarin sudah ada di forum ya guys. Ini untuk Source Code AVL Tree nya
#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int key;
    struct AVLNode *left;
Expand
Source_Code_AVL_Tree.txt
6 KB
zaloeskr — 29/05/2024 08:23
@everyone Untuk Modul Sesi 10 kemarin sudah ada di forum ya guys. Ini untuk Source Code Max-Heap Tree nya
#include <stdio.h>

#define MAX 100

int heap[MAX + 1];
int size = 0;
Expand
Heap.txt
3 KB
﻿
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menampilkan isi linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk menambahkan node di awal linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi Memori Gagal.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Fungsi untuk menambahkan node di tengah linked list
void insertInMiddle(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi Memori Gagal.\n");
        exit(1);
    }
    newNode->data = data;
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Posisi invalid.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk menambahkan node di akhir linked list
void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Fungsi untuk menghapus node di awal linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Linked list Kosong.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Fungsi untuk menghapus node di akhir linked list
void deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Linked list Kosong.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prevNode = NULL;
    while (temp->next != NULL) {
        prevNode = temp;
        temp = temp->next;
    }
    if (prevNode != NULL) {
        prevNode->next = NULL;
        free(temp);
    } else {
        free(head);
        head = NULL;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert in middle\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert in middle: ");
                scanf("%d", &data);
                printf("Enter position to insert in middle: ");
                scanf("%d", &position);
                insertInMiddle(head, data, position);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(head, data);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                deleteAtEnd(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
Singly_Linked_List.txt
5 KB
