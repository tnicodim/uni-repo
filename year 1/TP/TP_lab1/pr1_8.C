/* Se cere să se scrie funcția lui Ackermann pentru două numere m,n date ca parametri. Să se testeze 
funcția cu valori citite de la tastatură.
*/

#include <stdio.h>
#include <stdlib.h>

long int Ackermann(long int m, long int n) {
	if (m == 0)
		return n + 1;
	if (m > 0 && n == 0)
		return Ackermann(m - 1, 1);
	if (m > 0 && n > 0)
		return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main() {
	long int m, n;
	printf("Introduceti m: "); scanf("%ld", &m);
	printf("Introduceti n: "); scanf("%ld", &n);
	printf("\n--------------------------------------------------\nRezultatul functiei Ackermann pentru numerele %ld si %ld este %ld", m, n, Ackermann(m, n));
	return 0;
}