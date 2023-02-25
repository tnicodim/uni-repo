/*Determinarea radicalului de ordin 2 al unui numar naturale se poate face folosind "metoda Babiloniana". 
Astfel, pentru determinarea radicalului lui x se va folosi relatia de recurenta in care a0=1 si an+1=1/2∗(an+x/an). 
Implementati o functie care primeste drept parametri un numar natural (si orice alti parametri considerati necesari) 
si returneaza valoarea reala egala cu radicalul de ordinul doi al acelui numar, cu o precizie dorita.
*/

#include <stdio.h>
#include <math.h>


float babylon(float x0, int s) {
	float x;
	x = (x0 + (float)s / x0) / 2.0;
	if (fabs(x - x0) < 0.001)
		return x;
	else 
		return babylon(x,s);
}

int main() {
	int s;
	printf("Nr natural x = ");
	scanf("%d", &s);
	printf("SQRT de %d este aproximativ %f",s, babylon(1.0,s));
	return 0;
}