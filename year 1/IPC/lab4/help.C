#include <stdio.h> 
#include <stdlib.h>
#define citeste(x) scanf("%d",&x)

int main()
{
    int nr, i, s, j, a, b;
    printf("nr=");
    citeste(nr);


    for (i = 1; i <= nr; i++)
    {
        s = 0;
        for (j = 1; j <= i; j++) 
        {
            if ((i % j) == 0)
                s = s + 1;
        }
        printf("\nPentru %d, s=%d", i, s);
        if (s <= 2)
            printf("\n%d este prim", i);

    }
    return 0;
}