int cautareLiniara(int a[], int x, int n)
{
	int i;
	i = 0;
	while (a[i] != x && i < n)
		i++;
	return i;
}

int cautareFanionului(int a[], int x, int n)
{
	int i;
	i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	return i;
}

int cautareBinara(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	do {
		m = (s + d) / 2;
		if (a[m] < x)
			s = m + 1;
		else
			d = m - 1;
	} while (s <= d && a[m] != x);
	return m;
}

int cautareBinaraP(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	do {
		m = (s + d) / 2;
		if (x > a[m])
			s = m + 1;
		else
			d = m;
	} while (s < d);
	return d;
}

int cautareInterpolare(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	m = -1;
	if (x >= a[s] && x <= a[d])
		do {
			m = s + (x - a[s]) * (d - s) / (a[d] - a[s]);
			if (x > a[m])
				s = m + 1;
			else
				d = m - 1;
		} while (a[m] != x && s < d && x <= a[d] && x >= a[s] && a[d] != a[s]);
		return m;
}

void bbbbbbb(int a[], int n) {
	int i, j, aux;
	for (i = 1; i < n; i++) {
		j = i - 1;
		aux = a[i];
		while (a[j] > aux && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = aux;
	}
}

void asdasdasddd(int a[], int n) {
	int i, j, k_min, min;
	for (i = 0; i < n - 1; i++) {
		k_min = i;
		min = a[i];
		for (j = i; j < n; j++)
			if (min > a[j]) {
				k_min = j;
				min = a[j];
			}
		a[k_min] = a[i];
		a[i] = min;
	}
}

void sort_selectieP(int a[], int n) {
	int i, j, k_min, aux;
	for (i = 0; i < n - 1; i++) {
		k_min = i;
		for (j = i; j < n; j++)
			if (a[k_min] > a[j])
				k_min = j;
		aux = a[k_min];
		a[k_min] = a[i];
		a[i] = aux;
	}
}

void sadasaaaaaaaaaaaaaaa(int a[], int n) {
	int i, j, aux;
	for (i = 1; i < n; i++) {
		for (j = n - 1; j >= i; j--)
			if (a[j] < a[j - 1]) {
				aux = a[j];
				a[j] = a[j - 1];
				a[j - 1] = aux;
			}
	}
}

void afffffffffffffaa(int a[], int n) {
	int i, j, k, aux, s, d;
	s = 1; d = n - 1;
	do {
		for (i = d; i >= s; i--)
			if (a[i - 1] > a[i]) {
				aux = a[i];
				a[i] = a[i - 1];
				a[i - 1] = aux;
				k = i;
			}
		s = k + 1;
		for (i = s; i <= d; i++)
			if (a[i - 1] > a[i]) {
				aux = a[i];
				a[i] = a[i - 1];
				a[i - 1] = aux;
				k = i;
			}
		d = k - 1;
	} while (s <= d);
}

void bsadbad(int a[], int n) {
	int m, i, j, k, aux;
	int h[3] = { 3,2,1 };
	for (m = 0; m < 3; m++) {
		k = h[m];
		for (i = k; i < n; i++) {
			aux = a[i];
			j = i - k;
			while (a[j] > aux && j >= 0)
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = aux;
		}
	}
}

void SSSSSSSSAaaaa(int a[], int n, int s, int d) {
	int i, j, x, aux;
	x = a[(s + d) / 2];
	i = s; j = d;
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);
	if (s < j)
		Qsort(a, n, s, j);
	if (d > i)
		Qsort(a, n, i, d);
}

void deplasare(int a[], int s, int d) {
	int i, j, test, x;
	i = s; j = 2 * i;
	x = a[i];
	test = 1;
	while (j <= d && test == 1) {
		if (j < d)
			if (a[j] < a[j + 1])
				j++;
		if (x < a[j]) {
			a[i] = a[j];
			i = j;
			j = 2 * i;
		}
		else
			test = 0;
	}
	a[i] = x;
}

void sort_HeapSort(int a[], int n) {
	int s, d, aux;
	s = n / 2 + 1;
	d = n;
	while (s > 1) {
		s--;
		deplasare(a, s, d);
	}
	while (d > 0) {
		aux = a[1];
		a[1] = a[d];
		a[d] = aux;
		d--;
		deplasare(a, 1, d);
	}
}