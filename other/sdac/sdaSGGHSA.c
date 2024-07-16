#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int N, count = 1;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void citire(int a[], int n)
{
	int i;
	printf("Dati cele %d numere: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
}
void afisare(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void insertie(int a[], int n)
{
	int i, j, aux;
	for (i = 1; i < n; i++)
	{
		aux = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > aux)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}

		a[j + 1] = aux;
		printf("Etapa %d: ", i);
		afisare(a, n);
	}
}

int cautareBinara(int a[], int cautat, int s, int d)
{
	if (d <= s)
	{
		if (cautat > a[s])
			return (s + 1);
		else
			return s;
	}
	int m = (s + d) / 2;
	if (cautat == a[m])
		return m + 1;
	if (cautat > a[m])
		return cautareBinara(a, cautat, m + 1, d);
	return cautareBinara(a, cautat, s, m - 1);
}

void insertieBinara(int a[], int n)
{
	int i, j, aux, loc;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		aux = a[i];
		loc = cautareBinara(a, aux, 0, j);
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = aux;
		printf("\nEtapa %d: ", i);
		afisare(a, n);
	}
}

void selectie(int a[], int n)
{
	int i, j, k_min, aux;
	for (i = 0; i < n - 1; i++)
	{
		k_min = i;
		aux = a[i];
		for (j = i + 1; j < n; j++)
			if (a[j] < a[k_min])
			{
				k_min = j;
				aux = a[k_min];
			}
		a[k_min] = a[i];
		a[i] = aux;
		printf("\nEtapa %d: ", i + 1);
		afisare(a, n);
	}
}
void selectiePerformanta(int a[], int n)
{
	int i, j, k_min, aux;
	for (i = 0; i < n - 1; i++)
	{
		k_min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[k_min])
				k_min = j;
		aux = a[k_min];
		a[k_min] = a[i];
		a[i] = aux;
		printf("\nEtapa %d: ", i + 1);
		afisare(a, n);
	}
}

void bubbleSort(int a[], int n)
{
	int i, j, aux;
	for (i = 1; i < n; i++)
	{
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				aux = a[j - 1];
				a[j - 1] = a[j];
				a[j] = aux;
			}
		printf("\nEtapa %d: ", i);
		afisare(a, n);
	}

}

void shakeSort(int a[], int n)
{
	int  j, k, s, d, aux, count = 1;
	s = 1;
	d = n - 1;
	k = n - 1;
	do
	{
		for (j = d; j >= s; j--)
			if (a[j - 1] > a[j])
			{
				aux = a[j - 1];
				a[j - 1] = a[j];
				a[j] = aux;
				k = j;
			}
		s = k + 1;
		for (j = s; j <= d; j++)
			if (a[j - 1] > a[j])
			{
				aux = a[j - 1];
				a[j - 1] = a[j];
				a[j] = aux;
				k = j;
			}
		d = k - 1;
		printf("\nEtapa %d: ", count);
		afisare(a, n);
		count++;

	} while (s <= d);
}
void binsort(int a[], int n)
{
	int i, aux;
	for (i = 0; i < n; i++)
	{
		while (a[i] != i)
		{
			aux = a[a[i]];
			a[a[i]] = a[i];
			a[i] = aux;
		}
		printf("Etapa %d: ", i + 1);
		afisare(a, n);
	}
}

void shellsort(int a[], int n)
{
	int i, j, aux, l, k;
	int h[3] = { 3,2,1 };
	for (l = 0; l < 3; l++)
	{
		k = h[l];
		for (i = k; i < n; i++)
		{
			aux = a[i];
			j = i - k;
			while (j >= 0 && aux < a[j])
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = aux;
		}
		printf("Trecerea %d: ", l + 1);
		afisare(a, n);
	}
}

void heapify(int arr[], int n, int i)
{
	int aux;
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;
	// If largest is not root 
	if (largest != i)
	{
		aux = arr[i];
		arr[i] = arr[largest];
		arr[largest] = aux;

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{
	int aux;
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
		printf("Etapa %da: ", n / 2 - i);
		afisare(arr, n);
	}

	// One by one extract an element from heap 
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end 
		aux = arr[0];
		arr[0] = arr[i];
		arr[i] = aux;
		printf("Etapa %db: ", n - i);
		afisare(arr, n);
		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[(high + low) / 2];
	while (low <= high)
	{
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low <= high)
		{
			swap(&arr[low], &arr[high]);
			low++;
			high--;
		}
	}
}

void quickSort(int a[], int s, int d)
{
	if (s < d)
	{
		int pi = partition(a, s, d);
		printf("Etapa %d: ", count);
		count++;
		afisare(a, N);
		quickSort(a, s, pi - 1);
		quickSort(a, pi, d);
	}
}
int biti(int x, int k, int j)
{
	return (x >> k) & ~(~0 << j);
}
void radix_interschimbare(int a[], int s, int d, int b)
{
	int i, j, aux;
	if (d > s && b >= 0)
	{
		i = s;
		j = d;
		do
		{
			while (i < j && biti(a[i], b, 1) == 0)
				i++;
			while (i < j && biti(a[j], b, 1) == 1)
				j--;
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;

		} while (i != j);
		printf("Etapa %d: ", count);
		count++;
		afisare(a, N);
		if (biti(a[d], b, 1) == 0)
			j++;
		radix_interschimbare(a, s, j - 1, b - 1);
		radix_interschimbare(a, j, d, b - 1);
	}
}
void radix_direct(int a[], int n)
{
	int b, T[100], Numar[100], m, k, i, t;
	b = sizeof(int) * 8;
	m = 4;
	for (t = 0; t < b / m; t++)
	{
		for (i = 0; i < pow(2, m); i++)
			Numar[i] = 0;
		for (i = 0; i < n; i++)
		{
			k = biti(a[i], t * m, m);
			Numar[k]++;
		}
		for (i = 1; i < pow(2, m); i++)
			Numar[i] = Numar[i] + Numar[i - 1];
		for (i = n - 1; i >= 0; i--)
		{
			k = biti(a[i], t * m, m);
			T[Numar[k] - 1] = a[i];
			Numar[k]--;

		}
		printf("Etapa %d: ", t + 1);
		afisare(T, n);
		for (i = 0; i < n; i++)
			a[i] = T[i];
	}
}
int main()
{
	int a[20], n, opt, b;
	do
	{
		printf("1.Sortare prin insertie\n");
		printf("2.Sortare prin selectie\n");
		printf("3.Sortare Bubblesort\n");
		printf("4.Shakesort\n");
		printf("5.Binsort\n");
		printf("6.Shellsort\n");
		printf("7.Heap sort\n");
		printf("8.Quicksort\n");
		printf("9.Radix interschimbare\n");
		printf("10.Radix direct\n");
		printf("0.Iesire\n");
		printf("Dati optiunea: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("SORTAREA PRIN INSERTIE\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			insertie(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 2:
			printf("\nSORTAREA PRIN SELECTIE\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			selectie(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 3:
			printf("\nBUBLE SORT\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			bubbleSort(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 4:
			printf("\nSHAKE SORT\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			shakeSort(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 5:
			printf("\nBinsort\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			binsort(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 6:
			printf("Shellsort");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			shellsort(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 7:
			printf("\nHEAPSORT\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			heapSort(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 8:
			printf("\nQUICKSORT\n");
			printf("n=");
			scanf("%d", &n);
			N = n;
			count = 1;
			citire(a, n);
			quickSort(a, 0, n - 1);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 9:
			printf("\nRADIX INTERSCHIMBARE\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			b = sizeof(int) * 8;
			N = n;
			count = 1;
			radix_interschimbare(a, 0, n - 1, b - 1);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 10:
			printf("\nRADIX DIRECT\n");
			printf("n=");
			scanf("%d", &n);
			citire(a, n);
			radix_direct(a, n);
			printf("\nTabloul dupa sortare:\n");
			afisare(a, n);
			break;
		case 0:
			printf("\nAti oprit consola interactiva\n");
			break;
		default:
			printf("\nOPTIUNE INVALIDA\n");
			break;
		}
	} while (opt != 0);
	//getch();
	return 0;
}