/*
Aplicația 2.2: Folosind struct și union, definiți o structură de date care să poată memora următoarele informații
despre viețuitoare:
 tipul (poate fi: mamifer, insectă, pește, pasăre)
 durata medie de viață în ani
 dacă e mamifer: perioada de gestație, numărul mediu de pui pe care îi naște
 dacă e insectă: numărul de picioare, dacă poate să zboare sau nu, dacă este periculoasă sau nu pentru
om
 dacă e pește: tipul de apă: sărată/dulce, adâncimea maximă la care se poate întâlni, viteza maximă de
înot
 dacă e pasăre: anvergura aripilor, altitudinea maximă de zbor, viteza maximă de zbor
Definiți structura în așa fel încât memoria consumată să fie minimă. Citiți și afișați informațiile despre o
viețuitoare.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	enum {mamifer,insecta,peste,pasare}tip;
	int m_viata;
	union {
		struct { int gest, m_pui; }m;
		struct { int picioare, zb, pericol; }i;
		struct { int apa, h_max, v_max; }p;
		struct {int anv,h_max,v_max;}pa;
	}sp;
}an;

int n = -1;

void citire(an a[]) {
	n++;
	printf("Tipul animalului: (mamifer,insecta,peste,pasare)\n");
	scanf("%d", &(a+n)->tip);
	printf("\n-----------------------------------\n");
	switch ((a + n)->tip) {
	case 0:
		printf("Mamifer\n");
		printf("Medie viata(ani): ");
		scanf("%d", &(a + n)->m_viata);
		printf("Perioada de gestatie(zile): ");
		scanf("%d", &(a + n)->sp.m.gest);
		printf("Nr mediu de pui: ");
		scanf("%d", &(a + n)->sp.m.m_pui);
		break;
	case 1:
		printf("Insecta\n");
		printf("Medie viata(ani): ");
		scanf("%d", &(a + n)->m_viata);
		printf("Nr picioare: ");
		scanf("%d", &(a + n)->sp.i.picioare);
		printf("Zburatoare (0/1): ");
		scanf("%d", &(a + n)->sp.i.zb);
		printf("Periculoasa (0/1): ");
		scanf("%d", &(a + n)->sp.i.pericol);
		break;
	case 2:
		printf("Peste\n");
		printf("Medie viata(ani): ");
		scanf("%d", &(a+n)->m_viata);
		printf("Tipul apei (0/1): ");
		scanf("%d", &(a+n)->sp.p.apa);
		printf("Adancimea maxima(m): ");
		scanf("%d", &(a+n)->sp.p.h_max);
		printf("Viteza maxima(km/h): ");
		scanf("%d", &(a+n)->sp.p.v_max);
		break;
	case 3:
		printf("Pasare\n");
		printf("Medie viata(ani): ");
		scanf("%d", &(a+n)->m_viata);
		printf("Anvergura aripilor(m): ");
		scanf("%d", &(a+n)->sp.pa.anv );
		printf("Altitudinea maxima(m): ");
		scanf("%d", &(a+n)->sp.pa.h_max);
		printf("Viteza maxima(km/h): ");
		scanf("%d", &(a+n)->sp.pa.v_max);
		break;
	default:
		printf("\nERROR! INVALID ANIMAL TYPE\nERROR! INVALID ANIMAL TYPE\n\n\n");
		n--;
		citire(a);
		break;
	}
}

void afisare(an a[]) {
	int i;
	for (i = 0; i <= n; i++) {
		switch ((a + i)->tip) {
		case 0:
			printf("\nMamifer\n");
			printf("____________________________");
			printf("\nMedie viata(ani):");
			printf("%d ani", (a + i)->m_viata);
			printf("\nPerioada de gestatie: ");
			printf("%d zile", (a + i)->sp.m.gest);
			printf("\nNr mediu de pui: ");
			printf("%d", (a + i)->sp.m.m_pui);
			break;
		case 1:
			printf("\nInsecta\n");
			printf("____________________________");
			printf("\nMedie viata(ani): ");
			printf("%d ani", (a + i)->m_viata);
			printf("\nNr picioare: ");
			printf("%d", (a + i)->sp.i.picioare);
			if ((a + i)->sp.i.zb)
				printf("\nZburatoare");
			else
				printf("\nNezburatoare");
			if ((a + i)->sp.i.pericol)
				printf("\nPericulos");
			else
				printf("\nNepericulos");
			break;
		case 2:
			printf("\nPeste\n");
			printf("____________________________");
			printf("\nMedie viata(ani): ");
			printf("%d ani", (a + i)->m_viata);
			if ((a + i)->sp.p.apa)
				printf("\nMediul de trai: Apa dulce");
			else
				printf("\nMediul de trai: Apa sarata");
			printf("\nAdancimea maxima: ");
			printf("%d m", (a + i)->sp.p.h_max);
			printf("\nViteza maxima: ");
			printf("%d km/h", (a + i)->sp.p.v_max);
			break;
		case 3:
			printf("\nPasare\n");
			printf("____________________________");
			printf("\nMedie viata(ani): ");
			printf("%d ani", (a + i)->m_viata);
			printf("\nAnvergura aripilor: ");
			printf("%d m", (a + i)->sp.pa.anv);
			printf("\nAltitudinea maxima: ");
			printf("%d m", (a + i)->sp.pa.h_max);
			printf("\nViteza maxima: ");
			printf("%d km/h", (a + i)->sp.pa.v_max);
			break;
		default:
			printf("\nERROR!");
			break;
		}
	printf("\n\n");
	}
}

const char *numeTip[] = { "mamifer","insecta","peste","pasare" };


int main() {
	an a[10];
	citire(a); citire(a);
	afisare(a);
	printf("\n\n");
	return 0;
}