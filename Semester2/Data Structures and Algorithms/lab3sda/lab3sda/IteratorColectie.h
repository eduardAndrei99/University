#pragma once
#include "Colectie.h"
#include "Lista.h"

typedef int TElem;
class Colectie;

//iterator unidirectional pe un Container
class IteratorColectie {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container

	friend class Colectie;
	//contine o referinta catre containerul pe care il itereaza
	const Colectie& c;
	int elemCurent;
	int frecvCurent;
	int pas;
	/* aici e reprezentarea specifica a iteratorului*/

public:

	IteratorColectie(const Colectie& c) :c{ c } {
		Lista x = c.getLista();
		int size = x.size();
		if (size) {
			this->elemCurent = x[0].numar;
			this->frecvCurent = 1;
			pas = 0;
		}
	}

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const {
		return this->elemCurent;
	}

};
