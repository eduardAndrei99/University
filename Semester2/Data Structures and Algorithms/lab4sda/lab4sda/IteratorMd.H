#pragma once
#include "lista.h"
#include "MD.h"

//iterator unidirectional pe un Container
class IteratorMD {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	friend class MD;
	IteratorMD(const MD& m): m { m } {
		this->pozCheie = 0;
		this->pozValoare = 0;
	}

	//contine o referinta catre containerul pe care il itereaza
	const MD& m;
	/* aici e reprezentarea specifica a iteratorului*/

public:

	int pozCheie = 0;
	int pozValoare = 0;
	//reseteaza pozitia iteratorului la inceputul containerului
	void prim() {
		pozCheie = 0;
		pozValoare = 0;
	}

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator() {

		if (pozValoare == this->m.dimPozitie(this->pozCheie)-1) {
			pozCheie++;
			pozValoare = 0;
		}
		else {
			pozValoare++;
		}
	}

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const {
		return pozCheie <= m.l.size() - 1 && pozValoare < this->m.dimPozitie(this->pozCheie);
	}

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const {

		int i = 0;
		nodChei* k = this->m.l.getHead();
		while (i != this->pozCheie) {
			i++;
			k = k->urm;
		}
		vector<int>aux = m.cauta(k->cheie);
		TElem x;
		x.first = k->cheie;
		x.second = aux[this->pozValoare];
		return x;
	}

};
