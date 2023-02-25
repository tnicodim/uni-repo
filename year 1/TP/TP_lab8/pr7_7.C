/* Problema 7.7. Scrieţi un program care citeşte de la tastatură un număr N, 
apoi citeşte N numere întregi, iar la final afişează cele N numere în ordine inversă. 
Programul va folosi alocarea dinamică pentru memorarea celor N numere.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, *v, i;
	printf("Cate nr vreti sa cititi: ");
	scanf("%d", &n);
	v = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		printf("x%d=",i);
		scanf("%d", (v + i));
	}
	printf("\n");
	for (i = n - 1; i >= 0; i--)
		printf("%d ", *(v + i));
	printf("\n\n");
	free(v);
	return 0;
}