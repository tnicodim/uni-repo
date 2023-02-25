#include <stdio.h>
#include <stdlib.h>
#define N_MAX 1025
int v[N_MAX][N_MAX];
int d[N_MAX][N_MAX];
char m[N_MAX * N_MAX];
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int move(int i, int j)
{
    int N, S, E, W;
    N = S = E = W = 0;
    if (d[i][j] != 0)
        return d[i][j];

    if (v[i][j] < v[i - 1][j])
        N = move(i - 1, j) + 1;
    if (v[i][j] < v[i + 1][j])
        S = move(i + 1, j) + 1;
    if (v[i][j] < v[i][j + 1])
        E = move(i, j + 1) + 1;
    if (v[i][j] < v[i][j - 1])
        W = move(i, j - 1) + 1;

    d[i][j] = max(max(N, S), max(E, W));
    return d[i][j];
}
int main()
{
    FILE* f1 = fopen("alpin.in", "r"), * f2 = fopen("alpin.out", "w");
    int n, i, j, mx = -1, mxv;
    int maxi, maxj;
    fscanf(f1, "%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            fscanf(f1, "%d", &v[i][j]);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            mxv = mx;
            mx = max(mx, move(i, j));
            if (mxv != mx) {
                maxi = i;
                maxj = j;
            }
        }
    fprintf(f2, "%d\n", mx + 1);
    mx++;
    while (mx--) {
        if (d[maxi + 1][maxj] == mx)
            maxi++;
        else if (d[maxi - 1][maxj] == mx)
            maxi--;
        else if (d[maxi][maxj + 1] == mx)
            maxj++;
        else if (d[maxi][maxj - 1] == mx)
            maxj--;
        fprintf(f2, "%d %d\n", maxi, maxj);
    }
    return 0;
}