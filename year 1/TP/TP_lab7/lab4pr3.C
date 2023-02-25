#include <stdio.h>
#include <stdlib.h>

/*P 3: Se defineste o structura „Drept” care contine latimea l si inaltimea h a
dreptunghiului. Se cere nr<=5 si apoi cele nr dreptunghiuri. Sa se afiseze informatii despre
componentele dreptunghiului de arie maxima. Folositi definitia de tip typedef
*/

typedef struct {
	int l, h;
}Drept;

void citire(Drept* d, int* n) {
	(*n)++;
	printf("\nLatimea %d = ", *n);
	scanf("%d", &(d+*n)->l);
	printf("\nInaltimea %d = ", *n);
	scanf("%d", &(d+*n)->h);
}

void afisareSMax(Drept* d, int n) {
	int i, k = 0, max = (d->h)*(d->l);
	for (i = 1; i <= n; i++)
		if ((d + i)->h * (d + i)->l > max){
			max = (d + i)->h * (d + i)->l;
			k = i;
		}
		printf("\n\nDreptunghiul %d are cea mai mare suprafata:\nLatimea: %d\nInaltimea: %d\n\n\n", k, (d + k)->l, (d + k)->h);
}

int main() {
	Drept d[5];
	int i, nr, n = -1;
	printf("Nr de dreptunghiuri: ");
	scanf("%d", &nr);
	for (i = 0; i < nr; i++)
		citire(d, &n);
	afisareSMax(d, n);
	return 0;
}