/* Aplicația 2.14: Se citește un număr n<=10 de produse și pentru fiecare produs vânzările lui trimestriale pe un an
(4 valori). Se cere să se afișeze care produse au înregistrat o creștere continuă a vânzărilor în decurs de un an.
*/

#include <stdio.h>
#include <stdlib.h>

void citire(int a[50][50], int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		printf("\nProdusul %d\n~~~~~~~~~~~~~~~~~~~~~~", i+1);
		j = 0;
		a[i][j] = i+1;
		for (j = 1; j < 5; j++)
		{
			printf("\nVanzari trimestrul %d (u): ", j);
			scanf("%d", &a[i][j]);
		}
	}
}

void afisareCrestere(int a[50][50], int size) {
	int i, j, k;
	for (i = 0; i < size; i++)
	{
		k = 1;
		for (j = 1; j < 4; j++)
			if (a[i][j] > a[i][j + 1])
				k = 0;
		if (k)
			printf("\nProdusul %d a inregistrat o crestere continua:\n%d %d %d %d", i+1, a[i][1], a[i][2], a[i][3], a[i][4]);
	}
}

int main() {
	int a[50][50], size;
	printf("Numarul de produse = ");
	scanf("%d", &size);
	citire(a, size);
	afisareCrestere(a, size);
	printf("\n\n");
	return 0;
}