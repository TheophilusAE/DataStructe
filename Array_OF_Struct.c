#include <stdio.h>
#include <string.h>
	
struct mahasiswa {
	int NIM;
	char name[10];
	char kelas[10];
	};
	
int main (){
	struct mahasiswa mhs;
	scanf ("%d", &mhs.NIM);
	printf ("%d", mhs.NIM);
}
	
typedef struct Students {
    char name[50];
    char branch[50];
    int ID_no;
} stu;

int main() {

    stu s[];
    strcpy(s.name, "Geeks");
    strcpy(s.branch, "CSE");
    s.ID_no = 108;

    printf("%s\n", s.name);
    printf("%s\n", s.branch);
    printf("%d", s.ID_no);
    return 0;
}

