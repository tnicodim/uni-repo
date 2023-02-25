/*
P7. Sa se descompuna un numar in factori primi memorand rezultatul sub forma unui
vector de structuri. Fiecare element va cuprinde doua campuri:
a. unul care contine divizorul prim
b. unul care contine puterea la care apare acesta in descompunere
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,ni,k=0,i=1,flag=0;
	int d[30], p[30];
	printf("Numarul pt descompus:");
	scanf("%d", &n);
	ni = n;
	while (n != 1) {
		i++;
		if (n % i == 0) {
			d[k] = i;
			p[k] = 1;
			flag = 1;
			n = n / i;
		}
		while (n % i == 0) {
			p[k]++;
			n = n / i;
		}
		if (flag)
			k++;
		flag = 0;
	}
	printf("\n\n");
	for (i = 0; i < k; i++) {
		printf("%d^%d ", d[i],p[i]);
		if (i != k-1)
			printf("* ");
	}
	printf("= %d\n\n", ni);
	return 0;
}