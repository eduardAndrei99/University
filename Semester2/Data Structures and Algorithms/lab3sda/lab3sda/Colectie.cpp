#include "Colectie.h"
#include "IteratorColectie.h"

int Colectie::nrElemsLista() {
	return l.size();
}

int Colectie::dim() const {
	Lista x = this->getLista();
	int dim = x.size();
	int ret = 0;
	for (int i = 0; i < dim; i++) {
		ret += x[i].frecventa;
	}
	return ret;
}

void Colectie::adauga(TElem e) {
	int dim = this->nrElemsLista();
	bool apare = 0;
	for (int i = 0; i < dim; i++) {
		if (l[i].numar == e) {
			l[i].frecventa++;
			apare = 1;
		}
	}
	if (!apare) {
		pereche per;
		per.numar = e;
		per.frecventa = 1;
		l.insert(per);
	}
}

bool Colectie::sterge(TElem e) {
	Lista x = this->getLista();
	int dim = x.size();
	for (int i = 0; i < dim; i++) {
		if (x[i].numar == e && x[i].frecventa>0) {
			x[i].frecventa--;
			return true;
		}
	}
	return false;
}

bool Colectie::cauta(TElem elem) const {
	Lista x = this->getLista();
	int dim = x.size();
	for (int i = 0; i < dim; i++) {
		if (x[i].numar == elem && x[i].frecventa) {
			return true;
		}
	}
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	Lista x = this->getLista();
	int dim = x.size();
	for (int i = 0; i < dim; i++) {
		if (x[i].numar == elem) {
			return x[i].frecventa;
		}
	}
	return false;
}

//verifica daca colectia e vida;
bool Colectie:: vida() const {
	return l.size() == 0;
}

Colectie::Colectie() {

}

Colectie::~Colectie() {

}

IteratorColectie Colectie::iterator() const {
	return IteratorColectie(*this);
}