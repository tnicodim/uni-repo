#include <stdio.h>

#define p 30103


void euclid(int a, int b, int* x, int* y)
{
	if (!b) {
		*x = 1;
		*y = 0;
	}
	else {
		int x0, y0;
		euclid(b, a % b, &x0, &y0);
		*x = y0;
		*y = x0 - (a / b) * y0;
	}
}

int main(void)
{
	FILE* f_in = freopen("functii.in", "rt", stdin);
	FILE* f_out = freopen("functii.out", "wt", stdout);

	int x, y, n, s;
	scanf("%d %d", &n, &s);

	int factorial[n + 1];
	factorial[0] = 1;

	int i;
	for (i = 1; i <= n; i++)
		factorial[i] = (i * factorial[i - 1]) % p;


	euclid((factorial[n - s] * factorial[s]) % p, p, &x, &y);
	while (x < 0)
		x += p;
	x *= factorial[n];
	x %= p;

	int pow = 1;
	for (i = 0; i < s; i++)
		pow = (pow * 2) % p;

	printf("%d", (x * (pow - 2)) % p);
}