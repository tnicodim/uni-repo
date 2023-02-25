// 1. Sa se implementeze functiile strlen, strcpy, strcmp, strstr, strcat.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char sir[25], sir2[25];
	int opt;
	printf("\nIntroduceti sirul de caractere: ");
	gets(sir);
	while (1)
	{
		printf("\n1. Aflati lungimea sirului\n2. Comparati 2 siruri\n3. Gasiti un subsir in sirul initial\n4. Adaugati cuvinte primului sir\n5. Dublati sirul\n6.Iesire");
		printf("\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		printf("\n");
		switch (opt)
		{
		case 1:
			printf("\nLungimea sirului %s este %d", sir, strlen(sir));
			break;
		case 2:
			printf("\nIntroduceti sirul 2 de caractere: \n");
			getchar();
			gets(sir2);
			if (strcmp(sir, sir2) == 0)
				printf("Sirurile %s si %s sunt egale.", sir, sir2);
			else if(strcmp(sir, sir2) > 0)
				printf("Sirul %s este mai mare decat %s .", sir, sir2);
			else
				printf("Sirul %s este mai mic decat %s .", sir, sir2);
			break;
		case 3:
			printf("\nIntroduceti sirul de caractere cautat: \n");
			getchar();
			gets(sir2);
			if (strstr(sir,sir2) == NULL)
				printf("\n%s nu se gaseste in %s", sir2, sir);
			else 
				printf("\n%s se gaseste in %s", sir2, sir);
			break;
		case 4:
			printf("\nIntroduceti sirul care va fi adaugat: ");
			getchar();
			gets(sir2);
			strcat(sir, sir2);
			printf("\nNoul sir este %s", sir);
			break;
		case 5:
			strcpy(sir2, sir);
			strcat(sir, sir2);
			puts(sir);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nNu exista asa optiune");
			break;
		}
	}
	system("pause");
	return 0;
}