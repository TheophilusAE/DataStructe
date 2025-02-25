#include <stdio.h>
#include <stdlib.h>

#define M 7

int table_probing[M];

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

void insert_probing(int key, int (*hashFunc)(int)) {
    int idx = hashFunc(key);

    int i = 0;
    while (i < M) {
        int pos = (idx + i) % M;
        if (table_probing[pos] == 0) {
            table_probing[pos] = key;
            printf("Insert Success!\n");
            return;
        }
        i++;
    }
    printf("Table is full. Cannot insert.\n");
}

void view_probing() {
	int i;
    printf("The Data (Linear Probing)\n");
    printf(" Idx | Data\n");
    printf("-----+------\n");

    for (i = 0; i < M; i++) {
        printf("%3d | ", i);
        if (table_probing[i] == 0) {
            printf("NULL\n");
        } else {
            printf("%d\n", table_probing[i]);
        }
    }
}

int main() {
    int pilih, key, method, i;

    for (i = 0; i < M; i++) {
        table_probing[i] = 0;
    }

    do {
        system("cls");
        printf("\n1. Input (Linear Probing)\n");
        printf("2. View (Linear Probing)\n");
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
						insert_probing(key, divisionHash);
						system("pause");
						break;
                    case 2: 
						insert_probing(key, midSquareHash);
						system("pause"); 
						break;
                    case 3: 
						insert_probing(key, foldingHash); 
						system("pause");
						break;
                    case 4: 
						insert_probing(key, digitExtractionHash);
						system("pause");
						break;
                    default: printf("Metode salah.\n");
                }
                break;

            case 2:
                view_probing();
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

