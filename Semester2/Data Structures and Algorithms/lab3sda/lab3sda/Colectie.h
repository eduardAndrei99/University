//Colectie.h
#pragma once
#include "Lista.h"

class IteratorColectie;

class Colectie {
private:
	/* aici e reprezentarea */
	friend class IteratorColectie;
	Lista l;
public:
	//constructorul implicit
	Colectie();

	int nrElemsLista();
	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	Lista getLista() const {
		return this->l;
	}
	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

};