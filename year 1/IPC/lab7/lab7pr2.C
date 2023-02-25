/* 2. Sa se scrie un program C care sa citeasca de la tastatura un cuvant si sa verifice daca
respectivul cuvant este palindrom
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sir[20], sir2[20];
    int i,j;
    printf("Introduceti cuvantul dorit: ");
    gets(sir);
    j = strlen(sir)-1;
    for (i = 0; i < strlen(sir); i++)
    {
        sir2[i] = sir[j];
        j--;
    }
    sir2[strlen(sir)] = '\0';
    if (strcmp(sir, sir2) == 0)
        printf("\nCuvantul %s este palindrom!", sir);
    else 
        printf("\nCuvantul %s nu este palindrom!", sir);
    printf("\n");
    return 0;
}