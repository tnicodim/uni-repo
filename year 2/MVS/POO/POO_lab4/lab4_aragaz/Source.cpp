/* Să se realizeze o aplicaţie C++ care asigură evidența articolelor într-un magazin de electronice.
Aragazele sunt caracterizate după producator, culoare si pret.
Cuptoare cu microunde după producător, putere și preț.
Programul trebuie să permită următoarele:
-	introducerea unui nou articol de la tastatură.
-	Afișarea articolelor în ordinea producătorului
-   Afișarea tuturor articolelor care au prețul citit de la tastatura
-	Se vor șterge toate articolele care au un nume de productor citit de la tastatură
-	Ieșire
Observaţii:
Se va folosi o ierarhie de clase (1 clasă de bază și 2 clase derivate).
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Articol {
	int input;
public:
	string producator;
	int pret;
	int getInput();
	void setInput(int i);
};
class Aragaz :public Articol {
	string culoare;
public:
	Aragaz(string, int, string);
	Aragaz(string, int, string, int);
	void afisare();
};
class Microwave :public Articol {
	int putere;
public:
	Microwave(string, int, int);
	Microwave(string, int, int, int);
	void afisare();
};
int Articol::getInput() {
	return input;
}
void Articol::setInput(int i) {
	input = i;
}

Aragaz::Aragaz(string p, int pr, string c) {
	producator = p;
	pret = pr;
	culoare = c;
	setInput(0);
}
Aragaz::Aragaz(string p, int pr, string c, int i) {
	producator = p;
	pret = pr;
	culoare = c;
	setInput(i);
}
Microwave::Microwave(string p, int pr, int put) {
	producator = p;
	pret = pr;
	putere = put;
	setInput(0);
}
Microwave::Microwave(string p, int pr, int put, int i) {
	producator = p;
	pret = pr;
	putere = put;
	setInput(i);
}

void Aragaz::afisare() {
	cout << "\nProducator: " << producator << "\nPret: " << pret << "\nCuloare: " << culoare << "\n\n";
}
void Microwave::afisare() {
	cout << "\nProducator: " << producator << "\nPret: " << pret << "\nPutere (W): " << putere << "\n\n";
}

bool CompareProdA(const Aragaz& left, const Aragaz& right)
{
	return left.producator < right.producator;
}
bool CompareProdM(const Microwave& left, const Microwave& right)
{
	return left.producator < right.producator;
}

void onInit();

vector<Aragaz> aragazList;
vector<Microwave> microwaveList;

int main() {
	onInit();
	while (1) {
		int opt, opt2;
		cout << "\n------------------------------------------------\n1. Adaugare articol\n2. Afisare articole (ordinea producatorului)\n3. Afisare articole (pretul citit de la tastatura)\n4. Stergerea articolelor cu numele citit de la tastatura\n0. Exit\n------------------------------------------------\nAlegeti optiunea: ";
		cin >> opt;
		switch (opt) {
		case 1:
			do {
				cout << "\n------------------------\n1. Adaugare aragaz\n2. Adaugare microwave\n0. Back\n------------------------\nAlegeti optiunea: ";
				cin >> opt2;
				switch (opt2) {
				case 1:
				{
					string prod, cul;
					int pret;
					cout << "Producator: ";
					getline(cin, prod);
					getline(cin, prod);
					cout << "Culoare: ";
					getline(cin, cul);
					cout << "Pret: ";
					cin >> pret;
					Aragaz a(prod, pret, cul, 1);
					aragazList.push_back(a);
				}
				break;
				case 2:
				{
					string prod;
					int pret, put;
					cout << "Producator: ";
					getline(cin, prod);
					getline(cin, prod);
					cout << "Putere (W): ";
					cin >> put;
					cout << "Pret: ";
					cin >> pret;
					Microwave m(prod, pret, put, 1);
					microwaveList.push_back(m);
				}
				break;
				case 0:
					break;
				default:
					cout << "\nOptiune invalida!";
					break;
				}
			} while (opt2 != 0);
		case 2: {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\n       Aragaze\n~~~~~~~~~~~~~~~~~~~~~\n ";
			sort(aragazList.begin(), aragazList.end(), CompareProdA);
			for (auto aragaz : aragazList) {
				aragaz.afisare();
			}
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nCuptoare cu microunde\n~~~~~~~~~~~~~~~~~~~~~\n ";
			sort(microwaveList.begin(), microwaveList.end(), CompareProdM);
			for (auto microwave : microwaveList) {
				microwave.afisare();
			}
			break;
		}
		case 3: {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\n       Aragaze\n~~~~~~~~~~~~~~~~~~~~~\n ";
			for (auto aragaz : aragazList) {
				if (aragaz.getInput())
					aragaz.afisare();
			}
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nCuptoare cu microunde\n~~~~~~~~~~~~~~~~~~~~~\n ";
			for (auto microwave : microwaveList) {
				if (microwave.getInput())
					microwave.afisare();
			}
			break;
		}
		case 4:
			aragazList.clear();
			microwaveList.clear();
			onInit();
			break;
		case 0:
			exit(0);
		default:
			cout << "\nOptiune invalida!";
			break;
		}
	}
	return 0;
}

void onInit() {
	Aragaz a("Bosch", 800, "Chromium Grey");
	Aragaz a1("Goreen", 1200, "Metallic Black");
	Aragaz a2("Jysk", 550, "Matte White");
	Microwave m("Samsung", 250, 700);
	Microwave m1("Toshiba", 325, 1000);
	Microwave m2("Panasonic", 129, 300);
	aragazList.push_back(a);
	aragazList.push_back(a1);
	aragazList.push_back(a2);
	microwaveList.push_back(m);
	microwaveList.push_back(m1);
	microwaveList.push_back(m2);
}