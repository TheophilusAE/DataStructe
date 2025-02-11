#include <stdio.h>

typedef struct Mahasiswa {
    char nama[50];
    int umur;
    float nilai;
};

int main() {
    struct Mahasiswa mhs[3];
    
    for (int i = 0; i < 3; i++) {
        printf("Masukkan nama mahasiswa %d: ", i + 1);
        scanf(" %49[^\n]", mhs[i].nama);
        printf("Masukkan umur mahasiswa %d: ", i + 1);
        scanf("%d", &mhs[i].umur);
        printf("Masukkan nilai mahasiswa %d: ", i + 1);
        scanf("%f", &mhs[i].nilai);
    }
    
    printf("\nData Mahasiswa:\n");
    for (int i = 0; i < 3; i++) {
        printf("Nama: %s, Umur: %d, Nilai: %.2f\n", mhs[i].nama, mhs[i].umur, mhs[i].nilai);
    }
    
    return 0;
}
