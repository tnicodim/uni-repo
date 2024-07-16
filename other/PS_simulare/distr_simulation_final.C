// Proiect realizat de:
// TOLICO NICODIM
// CLINCE VLAD-ALEXANDRU
// VISALON MARIUS

#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846		
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mersenne.c"

float isValidX(float *x1, float *x2, int i) {
	while (*x1 >= *x2) {
		printf("\n!!! Tabloul de valori trebuie sa fie crescator !!!\nReintroduceti x[%d] = ", i);
		scanf("%f", x2);
	}
	return *x2;
}

int isValidpvect(float *x, float *p, int n) {
	float sum = 0;
	int i, j;
	for (i = 0; i < n; i++) {
		sum += p[i];
	}
	if (sum != 1)
		printf("\n!!! Suma probabilitatilor trebuie sa fie egala cu 1 !!!\n\n");
	else
		return 1;
	for (i = 0; i < n; i++) {
		if (i != n - 1) {
		printf(" x[%d] = %.2f \n p[%d] = ", i, x[i], i);
		scanf("%f", &p[i]);
		}
		else {
			p[i] = 1;
			for (j = 0; j < n - 1; j++)
				p[i] -= p[j];
			if (p[i] <= 0) {
				p[i] = 1000000;
				isValidpvect(x, p, n);
			}
			else
				printf("\np[n-1] este calculat automat...\n p[%d] = %.2f\n", i, p[i]);
		}
	}
	if (isValidpvect(x, p, n));
		return 1;
}

float isValidp(float p) {
	if (p > 0 && p < 1)
		return p;
	printf("\nProbabilitatea introdusa nu apartine interv. (0,1)!!!\nIncercati din nou:\n\n p = ");
	scanf("%f", &p);
	p = isValidp(p);
	return p;
}

void isValidAB(int* a, int* b) {
	while(*a >= *b){
		printf("\n!!! [a,b) => a trebuie sa fie mai mic ca b");
		printf("\n a = ");
		scanf("%d", a);
		printf(" b = ");
		scanf("%d", b);
	}
}
void isValidCD(int* c, int* d) {
	while (*c >= *d) {
		printf("\n!!! [c,d) => c trebuie sa fie mai mic ca d");
		printf("\n c = ");
		scanf("%d", c);
		printf(" d = ");
		scanf("%d", d);
	}
}

double urand(void){
	double u;
	u = genrand_real2();
	//printf("\n  Generatorul a returnat  numarul %1.15lf", u);
	return u;
}

int iterations(void) {
	int i;
	printf("\nCate valori doriti sa generati?\ni = ");
	scanf("%d", &i);
	return i;
}
int bernoulli(float p) {
	float u;
	u = urand();
	if (u < p) 
		return 1;
	return 0;
}

int binomiala(int n, float p) {
	double u;
	int i, x = 0;
	for (i = 1; i <= n; i++){
		u = urand();
		x += (u < p);
	}
	return x;
}

int geometrica(float p) {
	double u;
	int x;
	u = urand();
	x = (int)(log(1 - u)/log(1 - p)) + 1;
	return x;
}

int unifdiscreta(int n) {
	double u;
	int k;
	u = urand();
	k = (int)(n * u);
	return k;
}

float exponentiala(float theta) {
	double u;
	float x;
	u = urand();
	x = -1 * theta * log(1 - u);
	return x;
}
float unifcontinua(int a, int b) {
	double u;
	u = urand();
	return a + (b - a) * u;
}

float neunifdiscreta(float x[], float p[], int n) {
	float F,u;
	int k = 0;
	F = p[0];
	u = urand();
	while (u >= F) {
		k++;
		F += p[k];
	}
	return x[k];
}

void simDrept(int a, int b, int c, int d, float *x, float *y) {
	*x = a + abs(b-a) * urand();
	*y = c + abs(d-c) * urand();
}

void simCerc(int x0, int y0, int r, float *x, float *y) {
	do {
		*x = (x0-r) + 2*r * urand();
		*y = (y0-r) + 2*r * urand();
	} while ((pow(*x - x0, 2) + pow(*y - y0, 2)) > pow(r, 2));
}

void simElipsa(int x0, int y0, int a, int b, float* x, float* y) {
	do {
		*x = (x0-a) + 2 * abs(a) * urand();
		*y = (y0-b) + 2 * abs(b) * urand();
	} while ((pow(*x - x0, 2)/pow(a,2) + pow(*y - y0, 2)/pow(b,2) > 1));
}

float normala(float sigma, float m) {
	double u1, u2, r, z1, z2;
	u1 = genrand_real3();
	u2 = genrand_real3();
	r = sqrt(-2.0 * log(u1));
	z1 = r * cos(2 * M_PI * u2);
	z2 = r * sin(2 * M_PI * u2);
	//return z1;
	return (m + sigma*z1);
}

int main() {
	int opt1, opt2, i, it, n, a, b, j, c, d;
	int x0, y0, r;
	float alt_x, y, m, sigma, sigma2;
	float p, theta, x[30], prob[30];
	time_t secunde;
	secunde = time(NULL);
	init_genrand(secunde);
	start:
	while (1) {
		printf("\n--------------------------------------------------\n1. Distributii de probabilitate clasice discrete\n2. Distributii de probabilitate clasice continue\n3. Simularea vectorilor aleatori uniform distribuiti\n0. Iesire\n--------------------------------------------------\nOptiune >>  ");
		scanf("%d", &opt1);
		switch (opt1) {
		case 1:
			while (1) {
				printf("\n--------------------------------------------------\n1. Distributia Bernoulli\n2. Distributia Binomiala\n3. Distributia Geometrica\n4. Distributia Uniforma Discreta\n5. Distributia Neuniforma Discreta\n0. Inapoi la meniul principal\n--------------------------------------------------\nOptiune >>  ");
				scanf("%d", &opt2);
				switch (opt2) {
				case 0:
					goto start;
					break;
				case 1:
					printf("\n\nUn proces Bernoulli este un experiment aleator format \ndintr-un nr. cunoscut sau necunoscut de incercari \nindependente, fiecare incercare avand doar 2 posibilitati.\n\n   succesul -> 1; esecul -> 0\n p -> probabilitatea succesului\n q=1-p -> probabilitatea esecului\n\n O variabila aleatoare are o distr. Bernoulli daca \naceasta inregistreaza rezultatul unei singure incercari \ncoresp. unui proces Bernoulli.\nNotare: X ~ Bernoulli(p),  p<-(0,1), p+q=1 \n\n p = ");
					scanf("%f", &p);
					p = isValidp(p);
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %d", i, bernoulli(p));
					break;
				case 2:
					printf("\n\nO variabila aleatoare distribuita binomial cuantifica \nnr de k-succese din n-incercari asociate unui proces Bernoulli\n\nNotare: X ~ Bin(n,p), n<-N*, p<-(0,1)\n\nn -> nr de incercari\np -> prob. succesului\n\n n = ");
					scanf("%d", &n);
					printf("\n p = ");
					scanf("%f", &p);
					p = isValidp(p);
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %d", i, binomiala(n,p));
					break;
				case 3:
					printf("\n\nO variabila aleatoare geometrica cuantifica nr. \nde incercari pana la primul succes(inclusiv)\n\nNotare: X ~ Geom(p), p<-(0,1)\n p -> prob. succesului\n\n p = ");
					scanf("%f", &p);
					p = isValidp(p);
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %d", i, geometrica(p));
					break;
				case 4:
					printf("\n\nDaca U ~ Unif[0,1) - variabila aleatoare uniform distribuita pe \nintervalul [0,1) si n<-N*, atunci X = [nU] ~ Unif{0,1,2,...,n-1}\nunde [x] - partea intreaga a lui x; n - nr de elemente\n\n n = ");
					scanf("%d", &n);
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %d", i, unifdiscreta(n));
					break;
				case 5:
					printf("\n\nFie X - variabila aleatoare discreta\nValorile sale sunt ordonate crescator => x[0]<x[1]<...<x[n-1]\nTinand seama ca (sigma)p[k]=1 unde k=0;n-1, divizam intervalul [0,1) \nprin punctele 0,F[0]=p[0],F[1]=p[0]+p[1],...,F[k]=p[0]+p[1]+...+p[k],...,F[n-1]=1\n\nPentru simularea unei v.a.d. neunif. vom avea nevoie de \nn - nr de elemente, x[] - tabloul de valori, p[] - tabloul de probabilitati");
					printf("\n n = "); scanf("%d", &n); printf("\n");
					for (i = 0; i < n; i++) {
						printf(" x[%d] = ", i); scanf("%f", &x[i]); 
						if (i != 0) 
							x[i] = isValidX(&x[i - 1], &x[i], i);
						if (i != n - 1) { printf(" p[%d] = ", i); scanf("%f", &prob[i]); prob[i] = isValidp(prob[i]); printf("\n"); }
						else { 
							prob[i] = 1;
							for (j = 0; j < n - 1; j++)
								prob[i] -= prob[j];
							if (prob[i] <= 0) {
								prob[i] = 1000000;
								isValidpvect(x, prob, n);
							}
							else 
								printf("\np[n-1] este calculat automat...\n p[%d] = %.2f\n", i, prob[i]); }
					}
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %.2f", i, neunifdiscreta(x,prob,n));
					break;
				default:
					printf("\n\n!!! OPTIUNE INEXISTENTA !!!\n\n");
					break;
				}
			}
		case 2:
			while (1) {
				printf("\n--------------------------------------------------\n1. Distributia Exponentiala\n2. Distributia Uniforma Continua\n3. Distributia Normala\n0. Inapoi la meniul principal\n--------------------------------------------------\nOptiune >>  ");
				scanf("%d", &opt2);
				switch (opt2) {
				case 0:
					goto start;
					break;
				case 1:
					printf("\n\nDistributia exponentiala cuantifica timpul pana la producerea \nprimului eveniment rar sau intre 2 evenimente rare consecutive.\n\nPentru distr. exponentiala avem theta>0, iar functia de repartie este \nF(x)= {0, daca x < 0; 1-e^(-x/theta), daca x >= 0}\n\nNotare: X ~ Exp(theta)\ntheta - rate parameter\n");
				theta:
					printf("\n theta = ");
					scanf("%f", &theta);
					if (theta <= 0) {
						printf("\ntheta trebuie sa fie > 0");
						goto theta;
					}
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %f", i, exponentiala(theta));
					break;
				case 2:
					printf("\n\nFie a, b <- R cu a < b \nSimularea unei variabile aleatoare uniforme \npe intervalul [a, b) se bazeaza pe urmatorul rezultat : \n\nDaca U ~ Unif[0, 1), atunci variabila aleatoare X = a+(b-a)*U \neste o variabila aleatoare ce are distributia uniforma pe [a, b).\n\n a = ");
					scanf("%d", &a);
					printf("\n b = ");
					scanf("%d", &b);
					isValidAB(&a, &b);
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %f", i, unifcontinua(a, b));
					break;
				case 3:
					printf("\n\nDaca Z ~ N(0,1) atunci variabila aleatoare X = sigma*Z + m\nare distributia normala de medie m si dispersie sigma^2\n m = ");
					scanf("%f", &m);
					sigma:
					printf("\n sigma = ");
					scanf("%f", &sigma);
					if (sigma <= 0) {
						printf("\nsigma trebuie sa fie > 0");
						goto sigma;
					}
					it = iterations();
					for (i = 1; i <= it; i++)
						printf("\nX[%d] = %f", i, normala(sigma, m));
					break;
				default:
					printf("\n\n!!! OPTIUNE INEXISTENTA !!!\n\n");
					break;
				}
			}
			break;
		case 3:
			while (1) {
				printf("\n--------------------------------------------------\n1. Simularea v.a.u.d. intr-o multime dreptunghi\n2. Simularea v.a.u.d. intr-o multime cerc\n3. Simularea v.a.u.d. intr-o multime elipsa\n0. Inapoi la meniul principal\n--------------------------------------------------\nOptiune >>  ");
				scanf("%d", &opt2);
				switch (opt2) {
				case 0:
					goto start;
					break;
				case 1:
					printf("\n\nFie D(subset de)R^2 o multime marginita de arie nenula\nUn vector aleator (x,y) este unif. distr. pe D (x,y) ~ Unif(D)\nfXY(x,y)={1/aria(D), x,y<-D; 0, in rest}\n\nD=[a,b) x [c,d)\n\nDOAR VALORI INTREGI!\n a = ");
					scanf("%d", &a); 
					printf(" b = "); 
					scanf("%d", &b); 
					isValidAB(&a, &b);
					printf("\n c = "); 
					scanf("%d", &c); 
					printf(" d = "); 
					scanf("%d", &d); 
					isValidCD(&c, &d);
					it = iterations();
					for (i = 1; i <= it; i++)
					{
						simDrept(a, b, c, d, &alt_x, &y);
						printf("\nX[%d] = %.4f\tY[%d] = %.4f", i, alt_x, i, y);
					}
					break;
				case 2:
					printf("\n\nPentru simularea v.a.u.d. intr-o multime cerc vom avea:\nCentrul cercului C(x0,y0) si raza r > 0, unde (x-x0)^2 + (y-y0)^2 <= r^2\n\nDOAR VALORI INTREGI!\n x0 = ");
					scanf("%d", &x0); 
					printf(" y0 = "); 
					scanf("%d", &y0);
					raza:
					printf("\n r = ");
					scanf("%d", &r);
					if (r <= 0) {
						printf("\nr trebuie sa fie > 0");
						goto raza;
					}
					it = iterations();
					for (i = 1; i <= it; i++)
					{
						simCerc(x0, y0, r, &alt_x, &y);
						printf("\nX[%d] = %.4f\tY[%d] = %.4f", i, alt_x, i, y);
					}
					break;
				case 3:
					printf("\n\nPentru simularea v.a.u.d. intr-o multime elipsa vom avea:\nCentrul C(x0,y0), a,b si E, unde E=(1/a^2)*[(x-x0)^2] + (1/b^2)*[(y-y0)^2] <= 1\n\nDOAR VALORI INTREGI!\n x0 = ");
					scanf("%d", &x0);
					printf(" y0 = ");
					scanf("%d", &y0); 
					printf("\n a = ");
					scanf("%d", &a);
					printf(" b = ");
					scanf("%d", &b);
					it = iterations();
					for (i = 1; i <= it; i++)
					{
						simElipsa(x0, y0, a, b, &alt_x, &y);
						printf("\nX[%d] = %.4f\tY[%d] = %.4f", i, alt_x, i, y);
					}
					break;
				default:
					printf("\n\n!!! OPTIUNE INEXISTENTA !!!\n\n");
					break;
				}
			}
			break;
		case 0:
			exit(0);
		default:
			printf("\n\n!!! OPTIUNE INEXISTENTA !!!\n\n");
			break;
		}
	}
		return 0;
}
