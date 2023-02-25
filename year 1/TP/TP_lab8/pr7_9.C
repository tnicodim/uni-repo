/* Problema 7.9. Se citesc de la tastatură cuvinte separate prin spaţii albe (spaţiu, tab sau enter). Pornind
de la cuvintele citite, se construieşte un şir de caractere după următoarele reguli:
 Primul cuvânt citit se adaugă la şirul de caractere;
 Fiecare din următoarele cuvinte citite se adaugă la şirul de caractere dacă ultimele două litere ale şirului
coincid cu primele două litere ale cuvântului (nu se face distincţie între literele mici şi cele mari);
 Cuvintele adăugate la şirul de caractere sunt despărţite de caracterul ’-’.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sirinitial[100], sir[100];
    int i, ii, j, prev, jj, k = 0;
    printf("Sir initial: ");
    gets(sirinitial);
    for (i = 0; i < strlen(sirinitial); i++) {
        if (sirinitial[i] == ' ') {
            if (!k) {
                prev = i;
                k++;
                for (j = 0; j < i; j++)
                    sir[j] = sirinitial[j];
                sir[j] = '-';
            }
            if (tolower(sirinitial[i + 1]) == tolower(sir[j - 2]) && tolower(sirinitial[i + 2]) == tolower(sir[j - 1])) {
                for (ii = i + 1; sirinitial[ii] != ' '; ii++) {
                    j++;
                    sir[j] = sirinitial[ii];
                }
                sir[++j] = '-';
            }
            prev = i;
        }
    }
    sir[j] = '\0';
    printf("\n");
    puts(sir);
    return 0;
}
