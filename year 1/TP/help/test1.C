#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum = 0;

int sum_recursive(int i,int k, int *ptr) {
	if (i == k - 1) {
		return ptr[i];
	}
	sum = ptr[i] + sum_recursive(i+1, k, ptr);
}

int main() {
	char sir[30];
	int i, *ptr, k = 0;
	do
	{
		printf("\nIntroduceti sirul (ultimul caracter sa nu fie cifra!): ");
		gets(sir);
		puts(sir);
	} while (sir[strlen(sir)-1] == '0' || sir[strlen(sir)-1] == '1' || sir[strlen(sir)-1] == '2' || sir[strlen(sir)-1] == '3' || sir[strlen(sir)-1] == '4' || sir[strlen(sir) - 1] == '5' || sir[strlen(sir) - 1] == '6' || sir[strlen(sir) - 1] == '7' || sir[strlen(sir) - 1] == '8' || sir[strlen(sir) - 1] == '9');
	ptr = (int*)malloc(sizeof(int));
	for (i = 0; i < strlen(sir); i++) {
		if (sir[i] == '0') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 0;
		}
		else if (sir[i] == '1') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 1;
		}
		else if (sir[i] == '2') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 2;
		}
		else if (sir[i] == '3') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 3;
		}
		else if (sir[i] == '4') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 4;
		}
		else if (sir[i] == '5') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 5;
		}
		else if (sir[i] == '6') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 6;
		}
		else if (sir[i] == '7') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 7;
		}
		else if (sir[i] == '8') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 8;
		}
		else if (sir[i] == '9') {
			k++;
			ptr = realloc(ptr, k * sizeof(int));
			ptr[k - 1] = 9;
		}
	}
	printf("\n");
	for (i = 0; i < k; i++)
		printf("%d ", ptr[i]);
	printf("\n\nSUMA ACESTOR CIFRE ESTE: %d\n\n", sum_recursive(0, k, ptr));
}