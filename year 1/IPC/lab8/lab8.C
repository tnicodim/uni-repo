#include <stdio.h>
#include <stdlib.h>

/*
    Sa se realizeze un program cu urmatorul meniu:
    1. Citirea a doua matrici de la tastatura (matrici patratice)
    2. Afisarea matricilor
    3. Sa se calculeze suma elementelor de pe diagonala principala si sa se afiseze sub forma unui vector
    4. Sa se inlocuiasca toate elementele mai mari de o valoare citita de la tastatura cu cifra 0 in a doua matrice
    0. Iesire
*/

void citireMatrice(int matrice[5][5], int* size)
{
    int i, j;
    printf("Dati dimensiunea matricei\n");
    scanf("%d", size);
    printf("Introduceti matricea\n");
    for (i = 0; i < *size; i++)
    {
        for (j = 0; j < *size; j++)
        {
            scanf("%d", &matrice[i][j]);
        }

    }
}

void afisareMatrice(int matrice[5][5], int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void sumaDiagonaleiPrincipale(int matrice_a[5][5], int matrice_b[5][5], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", matrice_a[i][i] + matrice_b[i][i]);
    }
    printf("\n");
}

int inlocuire(int matrice[5][5], int size)
{
    int num, i, j;
    int freq = 0;
    printf("Introduceti un numar\n");
    scanf("%d", &num);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (matrice[i][j] > num)
            {
                matrice[i][j] = 0;
                freq++;
            }
        }
    }
    return freq;
}

int main()
{
    int matrice_a[5][5], matrice_b[5][5];
    int opt, size_a, size_b;
    while (1)
    {
        printf("Alegeti o optiune\n");
        printf("1. Citirea a doua matrici de la tastatura (matrici patratice)\n");
        printf("2. Afisarea matricilor\n");
        printf("3. Sa se calculeze suma elementelor de pe diagonala principala si sa se afiseze sub forma unui vector\n");
        printf("4. Sa se inlocuiasca toate elementele mai mari de o valoare citita de la tastatura cu cifra 0 in a doua matrice\n");
        printf("0. Iesire\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            citireMatrice(matrice_a, &size_a);
            citireMatrice(matrice_b, &size_b);
            break;
        case 2:
            if (size_a)
            {
                afisareMatrice(matrice_a, size_a);
                printf("\n");
                afisareMatrice(matrice_b, size_b);
            }
            else
                printf("Matricile nu au fost initializate\n");
            break;
        case 3:
            if (size_a == size_b && size_a != 0)
            {
                sumaDiagonaleiPrincipale(matrice_a, matrice_b, size_a);
            }
            else
                printf("Matricile nu au fost initializate\n");
            break;
        case 4:
            if (size_b)
            {
                printf("S-au inlocuit %d caractere\n", inlocuire(matrice_b, size_b));
                afisareMatrice(matrice_b, size_b);
            }
            else
                printf("Matricile nu au fost initializate\n");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Optiune gresita\n");
            break;
        }
    }

    return 0;
}