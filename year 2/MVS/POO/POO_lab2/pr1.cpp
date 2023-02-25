#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class Carte {
	string titlu, numeAutor, editura;
	int anPublicare;
public:
	Carte(string t, string n, string e, int a);
	void afisareCarte();
};

Carte::Carte(string t, string n, string e, int a) {
	titlu = t;
	numeAutor = n;
	editura = e;
	anPublicare = a;
}

inline void Carte::afisareCarte() {
	cout << "\nTitlu: " << titlu << "\nAutor: " << numeAutor << "\nEditura: " << editura << "\nAn Publicare: " << anPublicare << "\n\n";
}


int main() {
	vector<Carte> cartiList;
	while (1){
		int opt;
		cout << "\n------------\n1. Adaugare carte\n2. Vizualizare carti\n------------\nAlegeti optiunea: ";
		cin >> opt;
		string titlu, autor, editura;
		int an;
		switch (opt) {
		case 1: {
			cout << "Titlu: "; 
			getline(cin,titlu);
			getline(cin, titlu);
			cout << "Autor: ";
			getline(cin, autor);
			cout << "Editura: ";
			getline(cin, editura);
			cout << "An Publicare: ";
			cin >> an;
			Carte c(titlu, autor, editura, an);
			cartiList.push_back(c);
			break;
		}
		case 2:
			for (auto carte : cartiList) {
				carte.afisareCarte();
			}
			break;
		default:
			cout << "\nOptiune invalida!";
			break;
	}
	}
	return 0;
}