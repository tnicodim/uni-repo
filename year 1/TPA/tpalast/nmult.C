#include <stdio.h>
#include <stdlib.h>

int nr;

void doCombinations(int n, int k, int w, int pas, int nrincep) {
    int i;
    if (pas == k - 1) {
        nr += (n - nrincep + 1);
    }
    else {
        for (i = nrincep; i + (k - pas - 1) * w <= n; i++)
            doCombinations(n, k, w, pas + 1, i + w);
    }
}

int main()
{
    FILE* fin, * fout;
    fin = fopen("nmult.in", "r");
    fout = fopen("nmult.out", "w");

    int n, k, w;
    fscanf(fin, "%d%d%d", &n, &k, &w);
    doCombinations(n, k, w, 0, 1);

    fprintf(fout, "%d\n", nr);
    fclose(fin);
    fclose(fout);
    return 0;
}