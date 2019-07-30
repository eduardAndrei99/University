#pragma once

#include "Colectie.h"

//iterator unidirectional pe un Container
class IteratorColectie {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorColectie(const Colectie& c) :c{ c } {
		pozCheie = 0;
		pozValoare = 0;
		if (this->c.vida()) {
			return;
		}
		while (this->c.chei[pozCheie] == nullptr) {
			pozCheie++;
		}
	}

	//contine o referinta catre containerul pe care il itereaza
	const Colectie& c;
	friend class Colectie;
	int pozCheie;
	int pozValoare;
	/* aici e reprezentarea specifica a iteratorului*/

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim() {
		if (this->c.vida()) {
			return;
		}
		pozCheie = 0;
		while (this->c.chei[pozCheie] == nullptr) {
			pozCheie++;
		}
		pozValoare = 0;
	}

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator() {
		listaValori* l = this->c.chei[this->pozCheie];
		if (pozValoare == l->size() - 1) {
			pozValoare = 0;
			pozCheie++;
			while (c.chei[pozCheie] == nullptr && pozCheie < mod) {
				pozCheie++;
			}
		}
		else {
			pozValoare++;
		}
	}

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const {

		if (this->pozCheie < mod
			&& c.chei[pozCheie] != nullptr
			&& pozValoare < c.chei[pozCheie]->size()) {
			return true;
		}

		return false;
	}

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const {
		listaValori* l = this->c.chei[this->pozCheie];
		for (int i = 0; i < l->size(); i++) {
			if (i == this->pozValoare) {
				return l->operator[](i);
			}
		}
	}

};
