#include <stdio.h>
#include <stdlib.h>

int setFlag(int n, int k) { //sets k bit of a number n to 1
	n = n | (1 << k);
	return n;
}
int unsetFlag(int n, int k) { //sets k bit of a number n to 0
	n = n & ~(1 << k);
	return n;
}
int getFlag(int n, int k) { //returns the value of k bit of number n
	n = (n >> k) & 1;
	return n;
}
int changeFlag(char n, int k) { //changes the value (1->0 or 0->1) of k bit of a number n
	n = n ^ (1 << k);
	return n;
}

void printareValori(char a[]) {
	int i, j;
	printf("\nElementele multimii:\n-----------------------------\n");
	for (i = 0; i <= 125; i++)
		for (j = 0; j <= 7; j++)
			if (getFlag(a[i], j) == 1)
				printf("%d ", (i*8+j));
	printf("\n-----------------------------\n");
}

void adaugareNumar(char a[]) {
	int i, x;
	printf("\nx = ");
	scanf("%d", &x);
	a[x/8] = setFlag(a[x / 8], x % 8);
	printf("\n");
}


int main() {
	int i, opt;
	char a[126];
	char b = 0;
	for (i = 0; i < 126; i++)
		a[i] = 0;
	while (1) {
		printf("1. Adaugare numar\n2. Afisare valori introduse\n0. Exit\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt) {
		case 1:
			adaugareNumar(a);
			break;
		case 2:
			printareValori(a);
			break;
		case 0:
			exit(0);
		default:
			printf("\n------------------------------------------\nOptiune inexistenta! Incercati din nou\n------------------------------------------\n");
			break;
		}
	}
	return 0;
}