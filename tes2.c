#include <stdio.h>

int main (){
	int arr[10];
	
	for (int i = 0; i < 10;i++){
		printf("Masukan angka ke - %d : ", i);
		scanf ("%d", &arr[i]);
	}
	
	printf("\n");
	
	for (int i = 0; i < 10;i++){
		printf ("%d ", arr[i]);
	}
}


