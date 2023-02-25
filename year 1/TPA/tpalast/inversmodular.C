#include<stdio.h>
#define infile "inversmodular.in"
#define outfile "inversmodular.out"
int a, n;

void gcd(long long* x, long long* y, int a, int b)
{
	if (!b)
		*x = 1, * y = 0;
	else
	{
		gcd(x, y, b, a % b);
		long long aux = *x;
		*x = *y;
		*y = aux - *y * (a / b);
	}
}

int main()
{
	long long inv = 0, ins;
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);

	scanf("%d %d", &a, &n);
	gcd(&inv, &ins, a, n);

	if (inv <= 0)
		inv = n + inv % n;

	printf("%lld\n", inv);

	fclose(stdin);
	fclose(stdout);
	return 0;
}