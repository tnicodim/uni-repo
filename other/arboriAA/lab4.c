#include <stdio.h>
#include <stdlib.h>

#define N 25

int matrix[N][4];
int init = 0;
int first;

void initArrays() {
	int i;
	for (i = 1; i < N; i++) {
		matrix[i][0] = -1;
		matrix[i][1] = 0;
		matrix[i][2] = 0;
		matrix[i][3] = -1;
	}
	matrix[0][0] = -2;
	matrix[0][1] = -2;
	matrix[0][2] = -2;
	matrix[0][3] = -2;
}

void insert(int key, int parent) {
	int i, j;
	if (init == 0 || init == 1) {
		matrix[init + 1][3] = init;
		matrix[init + 1][2] = 0;
		matrix[init + 1][1] = 0;
		matrix[init + 1][0] = key;
		if (init == 1)
			matrix[1][1] = 2;
		++init;
	}
	else {
		for (i = 1; i < N; i++)
			if (matrix[i][3] == -1) {
				matrix[i][0] = key;
				for (j = 1; j < i; j++)
					if (matrix[j][0] == (char)parent)
					{
						matrix[i][3] = j;
						if (!matrix[j][1])
							matrix[j][1] = i;
						else {
							matrix[i - 1][2] = i;
						}
						return;
					}
				printf("\nParinte inexistent!!\n");
				matrix[i][0] = -1;
				return;
			}
	}
}

void printVectors() {
	int i;
	printf("\n    keys fson rbrother A");
	for (i = 1; i < N; i++) {
		if (matrix[i][3] != -1)
		{
			printf("\n%2d|   %c   %2d    %2d    %2d", i, (char)matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
		}
	}
	printf("\n");
}

void deletion(int i, int flag) {
	int j;
	if (flag == 1) {
	for (j = 1; j < i; j++)
		if (matrix[j][1] == i) {
			matrix[j][1] = matrix[i][2];
			break;
		}
	for (j = 1; j < i; j++)
		if (matrix[j][2] == i)
			matrix[j][2] = matrix[i][2];
	}
	matrix[i][0] = -1;
	matrix[i][1] = 0;
	matrix[i][2] = 0;
	matrix[i][3] = -1;
}

void deleteAdancime(char key) {
	int i, j, flag = 0;
	for (i = 1; i < N; i++) {
		if ((int)key == matrix[i][0]) {
			flag++;
			j = i;
		}
		if (flag == 1 && matrix[i][3] == j) {
			deleteAdancime((char)matrix[i][0]);
		}
	}
	printf("  %d", j);
	deletion(j,first);
}

void deleteNode(char key) {
	int k = -1, deleteStack[20];
	int i, j, found = 0;
	for (i = 1; i < N; i++) {
		if ((int)key == matrix[i][0]) {
			found++;
			deleteStack[++k] = i;
			if (matrix[i][1] == 0) {
				goto finalDeletion;
			}
		}
		if (found == 1 && matrix[i][3] == deleteStack[0]) {
			if (matrix[i][1] != 0)
				deleteNode((char)matrix[i][0]);
			else
				deleteStack[++k] = i;
		}
	}
			finalDeletion:
	for (i = 0; i <= k; i++)
		if (i == 0)
			deletion(deleteStack[i], 1);
		else
			deletion(deleteStack[i], 0);
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
			//deleteNode(key);
			first = 1;
			deleteAdancime(key);
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