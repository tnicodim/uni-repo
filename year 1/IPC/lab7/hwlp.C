#include <stdio.h>
#include <string.h>
#include <ctype.h>

int digits(char sir[30], int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (isdigit(sir[i]) != 0)
            count++;
    return count;

}

void micmare(char sir[30], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (islower(sir[i]) != 0)
        {
            printf("%c", sir[i]);
            sir[i] = toupper(sir[i]);
        }
    printf("\n");
    puts(sir);
}

void sufixe(char sir[30], int n)
{
    int i, j;
}

void eliminavocale(char sir[30], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if ((sir[i] == 'a') || (sir[i] == 'o') || (sir[i] == 'e') || (sir[i] == 'u') || (sir[i] == 'i') || (sir[i] == 'A') || (sir[i] == 'O') || (sir[i] == 'E') || (sir[i] == 'U') || (sir[i] == 'I'))
            {
            for (j = i; j < n; j++)
            {
                sir[j] = sir[j + 1];
            }
            n--;
            i--;
            }
    }
    printf("\n");
    puts(sir);
}

int main()
{
    int opt;
    char sir[30];
    printf("\nIntroduceti sirul: ");
    scanf("%s", sir);
    printf("\nSirul introdus este: ");
    puts(sir);
    while (1)
    {
        printf("\n1. Numarul de cifre din sir");
        printf("\n2. Inlocuieste toate literele mici in litere mari");
        printf("\n3. Afiseaza toate sufixele sirului");
        printf("\n4. Elimina toate vocalele din sir");
        printf("\nAlegeti optiunea dorita: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nNumarul de cifre din sir este %d", digits(sir, strlen(sir)));
            break;
        case 2:
            micmare(sir, strlen(sir));
            break;
        case 3:
            sufixe(sir, strlen(sir));
            break;
        case 4:
            eliminavocale(sir, strlen(sir));
            break;
        case 0:
            exit(0);
        default:
            printf("\nOptiune inexistenta!");
            break;
        }
    }

    return 0;
}