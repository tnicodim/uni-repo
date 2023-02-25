/* Se cere un număr impar n>4. Să se deseneze cifra „8”, scris ca un pătrat cu o linie orizontală în 
mijloc, în așa fel încât pe verticală și pe orizontală să fie câte n steluțe. În program nu vor fi admise duplicări de 
cod.
*/

#include <stdio.h>
#include <stdlib.h>

void linieOrizontala(int n){
	int i;
	for (i = 0; i < n; i++)
		printf("*");	
}

void linieVerticala(int n) {
	int i, j;
	for (i = 0; i < n/2 - 1 ; i++){
		printf("\n*");
		for (j = 0; j < n - 2; j++)
			printf(" ");
		printf("*");
	}
	printf("\n");
}

int main() {
	int n;
	printf("Introduceti un numar impar >= 5: ");
	scanf("%d", &n);
	printf("\n");
	linieOrizontala(n);
	linieVerticala(n);
	linieOrizontala(n);
	linieVerticala(n);
	linieOrizontala(n);
	printf("\n");
	return 0;
}