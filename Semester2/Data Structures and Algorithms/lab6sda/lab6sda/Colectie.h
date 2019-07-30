#pragma once

//Colectie.h
#include "lista.h"
typedef int TElem;
const int mod = 6607;

class Colectie {
private:
	/* aici e reprezentarea */
	 listaValori* chei[6608];
	 friend class IteratorColectie;
public:
	//constructorul implicit
	Colectie() {
		for (int i = 0; i < mod; i++) {
			chei[i] = nullptr;
		}
	}

	//adauga un element in colectie
	void adauga(TElem e) {
		int poz = e % mod;
		if (poz < 0) {
			poz = -poz;
		}
		if (this->chei[poz] == nullptr) {
			listaValori* l = new listaValori;
			l->addValoare(e);
			this->chei[poz] = l;
		}
		else {
			chei[poz]->addValoare(e);
		}
		return;
	}

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e) {
		int poz = e % mod;
		if (poz < 0) {
			poz = -poz;
		}
		if (this->chei[poz] == nullptr) {
			return false;
		}
		else {
			bool ok =  chei[poz]->stergeValoare(e);
			if (chei[poz]->size() == 0) {
				chei[poz] = nullptr;
			}
			return ok;
		}
	}

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const {
		int poz = elem % mod;
		if (poz < 0) {
			poz = -poz;
		}
		if (chei[poz] == nullptr) {
			return false;
		}
		listaValori* l = chei[poz];
		for (int i = 0; i < l->size(); i++) {
			if (l->operator[](i) == elem) {
				return true;
			}
		}
		return false;
	}

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const {
		int poz = elem % mod;
		if (poz < 0) {
			poz = -poz;
		}
		if (this->chei[poz] == nullptr) {
			return 0;
		}
		listaValori* l = this->chei[poz];
		int nrAp{ 0 };
		for (int i = 0; i < l->size(); i++) {
			if (l->operator[](i) == elem) {
				nrAp++;
			}
		}
		return nrAp;
	}


	//intoarce numarul de elemente din colectie;
	int dim() const {
		int d{ 0 };
		for (int i = 0; i < mod; i++) {
			if (this->chei[i] != nullptr) {
				d += chei[i]->size();
			}
		}
		return d;
	}

	//verifica daca colectia e vida;
	bool vida() const {
		if (dim() == 0) {
			return true;
		}
		return false;
	}

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie() {

	}

};