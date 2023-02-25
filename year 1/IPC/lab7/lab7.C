/* Sa se creeze o aplicatie in C cu urmatorul meniu interactiv:
1. Citirea de la tastatura a unui sir de caractere (sirul considerat citit corect doar daca ultimul caracter este o litera mica)
2. Afisarea sirului de caractere
3. Sa se numere cate vocale contine sirul citit
4. Sa se sorteze caracterele din sirul citit alfabetic
5. Se mai citeste un sir de caractere de la tastatura, sa se verifice daca cele 2 siruri sunt egale (strcmp)
6. Se mai citeste un sir de caractere de la tastatura, sa se verifice daca cele 2 siruri sunt egale (fara functie)
7. Sa se numere cate cuvinte sunt in sirul citit
0. Iesire
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char sir[30], aux, sir2[30];
	int i, n, opt, ok, k, k1, vocale, ord;
	ok = 0;
	while (1)
	{
		printf("\n1. Citirea de la tastatura a unui sir de caractere ");
		printf("\n2. Afisarea sirului de caractere ");
		printf("\n3. Sa se numere cate vocale contine sirul citit ");
		printf("\n4. Sa se sorteze caracterele din sirul citit alfabetic ");
		printf("\n5. Sa se verifice daca cele 2 siruri sunt egale (strcmp)");
		printf("\n6. Sa se verifice daca cele 2 siruri sunt egale (fara functie)");
		printf("\n7. Sa se numere cate cuvinte sunt in sirul citit ");
		printf("\n0. Iesire");
		printf("\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			k = 0;
			k1 = 0;
			do
			{
				printf("\nIntroduceti sirul de caractere: ");
				if (k1 == 0)
				{
					getchar();
					k1++;
				}
				gets(sir);
				if ((sir[strlen(sir)-1] >= 'a') && (sir[strlen(sir) - 1] <= 'z'))
					k = 1;
				ok = 1;
			} while (!k);
			break;
		case 2:
			if (ok)
			{
				printf("\nSirul introdus este: ");
				puts(sir);
			}
			else
				printf("\nIntroduceti sirul de caractere!");
				break;
		case 3:
			if (ok)
			{
				vocale = 0;
				for (i = 0; i < strlen(sir); i++)
					if ((sir[i] == 'a') || (sir[i] == 'e') || (sir[i] == 'i') || (sir[i] == 'o') || (sir[i] == 'u') ||
						(sir[i] == 'A') || (sir[i] == 'E') || (sir[i] == 'I') || (sir[i] == 'O') || (sir[i] == 'U'))
						vocale++;
				printf("\nIn sir sunt %d vocale", vocale);
			}
			else
				printf("\nIntroduceti sirul de caractere!");
			break;
		case 4:
			if (ok)
			{
				do
				{
					ord = 1;
					for (i = 0; i < strlen(sir) - 1; i++)
					{
						if (sir[i] > sir[i + 1])
						{
							aux = sir[i];
							sir[i] = sir[i + 1];
							sir[i + 1] = aux;
							ord = 0;
						}
					}
						
				} while (!ord);
			}
			else
				printf("\nIntroduceti sirul de caractere!");
			break;
		case 5:
			if (ok)
			{
				printf("\nIntroduceti al 2-lea sir: ");
				getchar();
				gets(sir2);
				if (strcmp(sir, sir2) > 0)
					printf("\nSirul 1 este mai mare decat sirul 2");
				else if (strcmp(sir, sir2) == 0)
					printf("\nSirul 1 este egal sirul 2");
				else if (strcmp(sir, sir2) < 0)
					printf("\nSirul 1 este mai mic decat sirul 2");
					
			}
			else
				printf("\nIntroduceti sirul de caractere!");
			break;
		case 6:
			if (ok)
			{
				k = 1;
				printf("\nIntroduceti al 2-lea sir: ");
				getchar();
				gets(sir2);
				if (strlen(sir) == strlen(sir2))
				{
					for (i = 0; i < strlen(sir); i++)
						if (sir[i] != sir2[i])
							k = 0;
				}
				else
					k = 0;
				if (k == 1)
					printf("\nSirurile sunt egale");
				else
					printf("\nSirurile nu sunt egale");
			}
			else
				printf("\nIntroduceti sirul de caractere!");
			break;
		case 7:
			if (ok)
			{
				k = 1;
				for (i = 0; i < strlen(sir); i++)
					if ((sir[i] == ' ') || (sir[i] == '\t') || (sir[i] == '\n'))
						k++;
				printf("\nSunt %d cuvinte in sir", k);
			}
			else
				printf("\nIntroduceti sirul de caractere!");
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("\nNu exista asa optiune, incercati din nou");
			break;
		}
	}
	system("pause");
	return 0;
}