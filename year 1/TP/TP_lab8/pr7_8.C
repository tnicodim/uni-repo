/*Problema 7.8. Aceeaşi problemă ca mai sus, cu diferenţa că nu se ştie de la început câte numere vor fi introduse.
Programul va începe direct cu citirea numerelor, fără a-l citi pe N. Citirea se va încheia în momentul în
care se introduce numărul 0. Programul va folosi alocarea dinamică astfel încât spaţiul de memorie consumat
să fie minim.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int *v, n, i = 0;
	v = (int*)malloc(sizeof(int));
	do{
		v = (int*)realloc(v,(i+1)*sizeof(int));
		printf("x%d=", i);
		scanf("%d", (v + i));
		i++;
	} while (*(v + i-1) != 0);
	n = i-1;
	printf("\n");
	for (i = n - 1; i >= 0; i--)
		printf("%d ", *(v + i));
	printf("\n\n");
	free(v);
	return 0;
}