/*Realizati un program in C care permite uitilizatorului sa citeasca un numar de la tastatura, iar
apoi acesta poate sa calculeze urmatoarele:
1.inversul numarului
2.afisarea numarului de cifre pare din numar
3.afisarea numarului de cifre impare din numar
4.afisarea sumei cifrelor numarului
5.afisarea produsului cifrelor numarului. Se vor ignora toate cifrele egale cu 0 in calculul
produsului.
6.afisarea mediei aritmetice a cifrelor numarului
0.Iesire*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
    int op, sum = 0, r, aux, i, poz, prod = 1;
    float med = 0;
    long int n;
    printf("Alegeti un numar: ");
    scanf("%d", &n);
    do {
        printf("\n0.Iesire");
        printf("\n1.inversul numarului");
        printf("\n2.afisarea numarului de cifre pare din numar");
        printf("\n3.afisarea numarului de cifre impare din numar");
        printf("\n4.afisarea sumei cifrelor numarului");
        printf("\n5.afisarea produsului cifrelor numarului. Se vor ignora toate cifrele egale cu 0 in calculul produsului.");
        printf("\n6.afisarea mediei aritmetice a cifrelor numarului");
        printf("\nAlegeti optiunea dorita: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            while (n != 0) {
                r = n % 10;
                sum = sum * 10 + r;
                n = n / 10;

            }
            printf("Inversul nr. este: %d", sum);
            break;
        case 2:
            aux = 0;
            while (n != 0) {
                r = n % 10;
                if (r % 2 == 0)
                    aux++;
                n /= 10;
            }

            printf("Exista %d numere pare", aux);

            break;
        case 3:
            poz = 0;

            i = n % 10;
            if (i % 2 == 1)
                poz++;
            n = n / 10;

            printf("Exista %d numere impare", poz);
            break;
        case 4:
            while (n != 0) {
                r = n % 10;
                sum = sum + r;
                n /= 10;
            }
            printf("Suma cifrelor lui %d este: %d", n, sum);
            break;
        case 5:
            while (n != 0) {
                r = n % 10;
                if (r != 0) {
                    prod = prod * r;
                    n /= 10;
                }
                else n /= 10;


            }
            printf("Produsul cifrelor lui %d este: %d", n, prod);
            break;
        case 6:
            while (n != 0) {
                r = n % 10;
                med = med + r;
                n /= 10;
            }
            printf("Media aritmetica a cifrelor lui %d este: %.1f", n, med / 2);
            break;
        default:
            printf("\nOptiune inexistenta");
        }

    } while (op != 0);

    return 0;
}