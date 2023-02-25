/* Aplicația 3.11: Să se implementeze, fără a se folosi indecși, următorul program: se citește pe rând câte o
valoare întreagă și se inserează într-un vector, astfel încât vectorul să fie mereu sortat crescător. După fiecare
inserare se va afișa noul vector. Programul se termină la citirea valorii 0. Presupunem că vectorul va avea maxim
100 de elemente.
*/

#include <stdio.h>
#include <stdlib.h>

int flag = 1;

void inserareCresc(int* v, int n, int new_element){
	int i, j, aux;
	for (i = 0; i < n; i++)
		if (*(v + i) > new_element)
			break;
	for (j = n; j > i; j--)
		v[j] = v[j - 1];
	v[i] = new_element;
}

void citire(int* v, int* n) {
	int new_element;
	(*n)++;
	printf("v[%d] = ", *n);
	scanf("%d", &new_element);
	inserareCresc(v, *n, new_element);
	if (new_element == 0)
		flag = 0;
}


int main() {
	int *v, n = -1, i;
	v = (int*)malloc(sizeof(int) * 100);
	while (flag)
		citire(v, &n);
	printf("\nVectorul v este:\n");
	for (i = 0; i <= n; i++)
		printf("%d ", *(v+i));
	return 0;
}