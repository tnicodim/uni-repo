
#include <stdio.h>
#define maxn 6000001
#define oo 0x3f3f3f3f

int main() {
	FILE* fin = fopen("ssm.in", "r");
	FILE* fout = fopen("ssm.out", "w");
	int  n, i, val, left, right, sum = 0, pos = 0, sum_max = -oo;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &val);
		if (sum < 0) {
			sum = val;
			pos = i;
		}
		else {
			sum = sum + val;
		}
		if (sum > sum_max) {
			sum_max = sum;
			left = pos + 1;
			right = i + 1;
		}
	}
	fprintf(fout, "%d %d %d \n", sum_max, left, right);
	fclose(fin);
	fclose(fout);
	return 0;
}