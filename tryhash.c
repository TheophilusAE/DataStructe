#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define M 7

struct Data {
    int value;
    struct Data* next;
};

struct Data* table_chaining[M];

int divisionHash(int key) {
    return key % M;
}

int midSquareHash(int key) {
    int squared = key * key;
    return (squared / 10) % M;
}

int foldingHash(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 1000;
        key /= 1000;
    }
    return sum % M;
}

int digitExtractionHash(int key) {
    int hash = 0;
    while (key > 0) {
        hash += key % 10;
        key /= 10;
    }
    return hash % M;
}

void insert_chaining(int key, int (*hashFunc)(int)) {
    int idx = hashFunc(key);
    struct Data* newNode = (struct Data*)malloc(sizeof(struct Data));
    newNode->value = key;
    newNode->next = NULL;

    if (table_chaining[idx] == NULL) {
        table_chaining[idx] = newNode;
    } else {
        struct Data* ptr = table_chaining[idx];
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    printf("Insert Success!\n");
}

void view_chaining() {
	int i;
    printf("The Data (Chaining)\n");
    printf(" Idx | Data\n");
    printf("-----+------------------------\n");

    for ( i = 0; i < M; i++) {
        printf("%3d | ", i);
        if (table_chaining[i] == NULL) {
            printf("NULL\n");
        } else {
            struct Data* ptr = table_chaining[i];
            printf("%d", ptr->value);
            while (ptr->next != NULL) {
                ptr = ptr->next;
                printf(" -> %d", ptr->value);
            }
            printf("\n");
        }
    }
}

int main() {
    int pilih, key, method, i;

    for (i = 0; i < M; i++) {
        table_chaining[i] = NULL;
    }

    do {
        system("cls");
        printf("\n1. Input (Chaining)\n");
        printf("2. View (Chaining)\n");
        printf("3. Exit\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                printf("Masukkan key: ");
                scanf("%d", &key);
                printf("Pilih Metode Hashing:\n");
                printf("1. Division\n2. Mid Square\n3. Folding\n4. Digit Extraction\n");
                printf("Pilih metode: ");
                scanf("%d", &method);

                switch (method) {
                    case 1: 
						insert_chaining(key, divisionHash);
						system("pause");
						break;
                    case 2: 
						insert_chaining(key, midSquareHash);
						system("pause");
						break;
                    case 3: 
						insert_chaining(key, foldingHash);
						system("pause");
						break;
                    case 4: 
						insert_chaining(key, digitExtractionHash);
						system("pause");
						break;
                    default: printf("Metode salah.\n");
                }
                break;

            case 2:
                view_chaining();
                system("pause");
                break;

            case 3:
                break;

            default:
                printf("Input salah.\n");
                break;
        }
    } while (pilih != 3);

    return 0;
}

