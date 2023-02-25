# include <stdio.h>
# include <stdlib.h>

# define MAX_N 1000000

int l[MAX_N + 1];
int v[MAX_N + 1];
int d[MAX_N + 1];

int src(int val, int* v, int len) {
    int pos, pas;
    pos = -1;
    for (pas = 30; pas >= 0; pas--) {
        if (pos + (1 << pas) < len && v[pos + (1 << pas)] < val)
            pos += (1 << pas);
    }
    return pos;
}

void drum(int* d, int* v, int n, int m, FILE* fout) {
    if (!m)
        return;

    int i;
    i = n - 1;
    while (v[i] != d[n])
        i--;

    drum(d, v, i, m - 1, fout);
    fprintf(fout, "%d ", v[i]);
}

int main() {
    FILE* fin = fopen("scmax.in", "r"), * fout = fopen("scmax.out", "w");

    int n, m, i, j, nr;

    fscanf(fin, "%d", &n);

    m = 1;
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d", &nr);

        j = src(nr, l, m) + 1;

        l[j] = nr;
        d[i] = l[j - 1];

        if (j == m) {
            m++;
        }

        v[i] = nr;
    }

    fprintf(fout, "%d\n", m - 1);
    d[n] = l[m - 1];
    v[n] = 0;
    drum(d, v, n, m - 1, fout);

    fclose(fin);
    fclose(fout);

    return 0;
}