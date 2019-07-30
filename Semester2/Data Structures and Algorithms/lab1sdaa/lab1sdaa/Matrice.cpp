#include "Matrice.h"
#include <iostream>
// aici implementarea operatiilor din Container.h

Matrice::Matrice() {

}

Matrice::~Matrice() {

}

/*
 functie ce verifica daca un element apare in matrice
 returneaza true daca apare in matrice
 false daca nu apare in matrice
*/
bool Matrice::apare(int i, int j, int e) {
	int nrElems = linie[i + 1] - linie[i];
	for (int it = linie[i]; it <= linie[i] - 1 + nrElems; it++) {
		if (coloana[it] == j) {
			valoare[it] = e;
			return true;
		}
	}
	return false;
}

/*
functie ce returneaza pozitia unde ar trebui sa apara un element
*/
int Matrice::undeArTrebuiSaApara(int i, int j) {
	int nrElems = linie[i + 1] - linie[i];
	int it;
	for (it = linie[i]; it <= linie[i] - 1 + nrElems; it++) {
		if (coloana[it] > j) {
			return it;
		}
	}
	return it;
}

//Inserez in vectoru v pe pozitia poz elementul elem
int inserez(Vector& v, int poz, int elem) {
	int i;
	v.push_back(78);
	int n = v.getSize();
	for (i = n; i > poz; i--)
		v[i] = v[i - 1];
	v[poz] = elem;
	return elem;
}

/*
sterg pozitia poz 
*/
void sterg(Vector& v, int poz) {
	for (int i = poz; i <= v.getSize(); i++) {
		v[i] = v[i + 1];
	}
	v.scadUnu();
}

/*
modific pozitia i j
*/
TElem Matrice::modifica(int i, int j, TElem e) {
	if (i >= this->nrLin || j >= this->nrCol || i < 0 || j < 0) {
		throw std::exception("Pozitie invalida!");
	}

	//Cazul in care apare
	if (e != 0) {
		if (apare(i, j, e) == true) {
		return e;
		}
	}

	int unde = undeArTrebuiSaApara(i, j);
	for (int k = i + 1; k <= nrLinii(); k++) {
		linie[k]++;
	}
	inserez(coloana, unde, j);
	inserez(valoare, unde, e);
	return e;
}
