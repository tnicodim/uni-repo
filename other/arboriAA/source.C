#include <stdio.h>
#include <stdlib.h>
#define N 25

int keys[N], A[N];
int init = 0;

void initArrays() {
	int i;
	for (i = 0; i < N; i++) {
		A[i] = -1;
		keys[i] = -1;
	}
	A[0] = -2;
}

void insert(int key, int parent) {
	int i, j;
	if (init == 0 || init == 1) {
		A[init + 1] = init;
		keys[init + 1] = key;
		++init;
	}
	else {
		for (i = 1; i < N; i++)
			if (A[i] == -1) {
				keys[i] = key;
				for (j = 1; j < i; j++)
					if (keys[j] == (char)parent)
					{
						A[i] = j;
						return;
					}
				printf("\nParinte inexistent!!\n");
				keys[i] = -1;
				return;
			}
	}
}

void printVectors() {
	int i;
	for (i = 1; i < N; i++) {
		if (A[i] != -1)
		{
			printf("\nA[%d] = %d            key[%d] = %c", i, A[i], i, (char)keys[i]);
		}
	}
}

void deleteNode(char key) {
	int i, j;
	for (i = 1; i < N; i++) {
		if ((int)key == keys[i]) {
			for (j = i + 1; j < N; j++) {
				if (A[j] == i) {
					deleteNode((char)keys[j]);
				}
			}
			A[i] = -1;
			keys[i] = (int)'z';
		}
	}
	return;
}

int main(void) {
	int opt;
	char key, parent;
	initArrays();
	while (1) {
		printf("\n1. Inserare\n2. Stergere\n3. Afisare\nOptiunea: ");
		scanf("%d", &opt);
		printf("\n");
		switch (opt) {
		case 1:
			while (1) {
				if (init == 0 || init == 1) {
					printf("Cheie: ");
					scanf(" %c", &key);
					insert((int)key, (int)'z');
					continue;
				}
				printf("Cheie: ");
				scanf(" %c", &key);
				if (key == 'Z')
					break;
				printf("Parinte: ");
				scanf(" %c", &parent);
				insert((int)key, (int)parent);
			}
			break;
		case 2:
			printf("Cheie: ");
			scanf(" %c", &key);
			deleteNode(key);
			break;
		case 3:
			printVectors();
			break;
		default:
			printf("\nOptiune invalida!");
			break;
		}
	}
	return 0;
}