#pragma once

#include <vector>
#include "lista.h"
using std::vector;

class IteratorMD;
typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class MD {

private:
	friend class IteratorMD;
	/* aici e reprezentarea */
	listaChei l;
public:

	// constructorul implicit al MultiDictionarului
	MD() {

	}

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v) {
		this->l.add(c, v);
	}

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const {
		return this->l.cauta(c);
	}

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v) {
		return this->l.stergeCheieValoare(c, v);
	}

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const {
		return this->l.dim();
	}

	//verifica daca MultiDictionarul e vid 
	bool vid() const {
		return this->l.vid();
	}

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD() {

	}

	int dimPozitie(int poz) const{
		return this->l.dimListaCheie(poz);
	}

};