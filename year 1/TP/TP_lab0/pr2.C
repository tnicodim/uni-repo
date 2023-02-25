/*sa se scrie o functie care primeste ca caracter un vector de n numere intregi
si pune in vectorul original pe primele pozitii toate numerele prime pe care le gaseste in vector
functia va returna si numarul de numere prime gasite
+ functie care sa verifice daca numerele sunt prime
*/

#include <stdio.h>
#include <stdlib.h>

int isPrime(int x) {
	int k, i;
	k = 0;
	for (i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
		{
			k = 1;
			return 0;
		}
	}
	if (k == 0) {
		printf("\n%d is prime\n", x);
		return 1;
	}
}

int vectorPrime(int* v[], int nr) {
	int k, i, p, aux, n1, n2, vprime[20], vsimple[20];
	k = 0;
	p = 0;
	for (i = 0; i < nr; i++)
		if (isPrime(v[i]) == 1) {
			vprime[k] = v[i];
			k++;
		}
		else {
			vsimple[p] = v[i];
			p++;
		}
	aux = 0;
	for (i = 0; i < k; i++)
		v[i] = vprime[i];
	for (i = k; i < nr; i++)
	{
		v[i] = vsimple[aux];
		aux++;
	}
	return k;
}


int main(){
	int v[10];
	int i, nr;
	printf("Introduceti nr de elemente din vector: ");
	scanf("%d", &nr);
	printf("\nIntroduceti vectorul:\n");
	for (i = 0; i < nr; i++)
		scanf("%d", &v[i]);
	printf("\nIn vector sunt %d numere prime", vectorPrime(v, nr));
	printf("\nVectorul ordonat este: ");
	for (i = 0; i < nr; i++)
		printf("%d ", v[i]);
	printf("\n\n\n");
	return 0;
}