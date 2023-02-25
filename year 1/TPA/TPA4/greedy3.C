#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fractional Knapsack Problem (m. greedy)

int n, capacity;

typedef struct {
	int weight;
	int value;
	float ratio;
}obiect;

void rucsac(obiect *items, int capacity){
	int i = 0;
	float totalw = 0, totalval = 0, last;
	while (totalw + (items+i)->weight < capacity){
		totalw += (items + i)->weight;
		totalval += (items + i)->value;
		i++;
	}
	last = (capacity - totalw) / (float)(items+i)->weight;
	totalw += last * (items + i)->weight;
	totalval += last * (items + i)->value;
	printf("\n\nMax value : %.3f\n\n", totalval);
}

int main() {
	obiect items[20], aux;
	float rmax;
	int i,j;
	printf("Nr de obiecte: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("-------------------\nObiectul %d:",i);
		printf("\nGreutate: ");
		scanf("%d", &(items+i)->weight);
		printf("Valoare: ");
		scanf("%d", &(items+i)->value);
		(items + i)->ratio = (float)(items + i)->value / ((items + i)->weight);
	}
	printf("Capacitatea rucsacului: ");
	scanf("%d", &capacity);
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++) {
			if ((items + i)->ratio < (items + j)->ratio) {
				aux = *(items + i);
				*(items + i) = *(items + j);
				*(items + j) = aux;
			}
		}
	rucsac(items, capacity);
	return 0;
}