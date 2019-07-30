//Matrice.h

#pragma once
#include "Vector.h"
#include <exception>
#define NULL_TELEMENT 0
//typedef int TElem;

class Matrice {
private:
	int nrLin;
	int nrCol;
	Vector linie;
	Vector coloana;
	Vector valoare;
public:

	Matrice();

	Matrice(int lin, int col) :nrLin(lin), nrCol(col) {
		linie.setSize(lin);
		coloana.setSize(col);
		for (int i = 0; i <= lin; i++) {
			linie.push_back(0);
		}
	}

	// returnare numar linii
	int nrLinii() const {
		return this->nrLin;
	}

	// returnare numar coloane
	int nrColoane() const {
		return this->nrCol;
	}

	// returnare element de pe o linie si o coloana
	//arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii ii consideram de la 0
	TElem element(int i, int j)  const{
		if (i > this->nrLin || j > this->nrCol || i < 0 || j < 0) {
			throw std::exception("Poz invalida");
		}
		for (int k = this->linie[i]; k <= this->linie[i + 1] - 1; k++) {
			if (this->coloana[k] == j) {
				return this->valoare[k];
			}
		}
		return 0;
	}

	// modifica elementul de pe o linie si o coloana si returneaza vechea valoare
	//arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem e);

	// destructor
	~Matrice();
		
	bool apare(int i, int j, int e);
	int undeArTrebuiSaApara(int i, int j);
};
