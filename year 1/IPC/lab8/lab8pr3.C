/* 
Sa se realizeze un program care sa determine daca un numar citit de la tastatura este prim,
utilizand o functie definita de utilizator
*/

#include <stdio.h>
#include <stdlib.h>

int isPrime(int x)
{
	int i, prime;
	prime = 0;
	for (i = 1; i <= x; i++)
			if ((x % i) == 0)
				prime++;
	if (prime > 2)
		return 0;
	else
		return 1;

}

int main()
{
	int x;
	printf("Introduceti numarul natural x = ");
	scanf("%d", &x);
	if (isPrime(x) == 1)
		printf("%d este prim", x);
	else 
		printf("%d nu este prim", x);
	return 0;
}