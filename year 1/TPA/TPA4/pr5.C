/* Scrieţi o funcţie (recursiva) care, dat fiind un întreg nenegativ 
returnează valoarea pe care cifrele sale în baza 10 o reprezintă în hexazecimal.
Exemplu: f(312) = 3 * 256 + 1*16 + 2 = 786.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int aux, digits;

int hexa(int x) {
	digits--;
	aux = aux / 10;
	if (digits == -1)
		return x;
	return ((x/(int)pow(10,digits) * pow(16,digits)) + hexa(x % aux));
}

int main() {
	int x, xt;
	printf("Intreg nenegativ x = ");
	scanf("%d", &x);
	xt = x;
	digits = log10(x) + 1;
	aux = pow(10, digits);
	printf("\nValoarea cifrelor lui %d in hexazecimal este %d\n\n", xt, hexa(x));
	return 0;
}