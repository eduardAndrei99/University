#include "IteratorColectie.h"

//reseteaza pozitia iteratorului la inceputul containerului
void IteratorColectie::prim() {
	Lista x = c.getLista();
	int size = x.size();
	if (size) {
		this->elemCurent = x[0].numar;
		this->frecvCurent = 1;
		pas = 0;
	}
}

void IteratorColectie::urmator() {
	Lista x = c.getLista();
	if (frecvCurent == x[pas].frecventa) {
		frecvCurent = 1;
		pas++;
		if (valid()) {
			elemCurent = x[pas].numar;
		}
	}
	else {
		frecvCurent++;
	}
}

//verifica daca iteratorul e valid (indica un element al containerului)
bool IteratorColectie::valid() const {
	Lista x = c.getLista();
	int size = x.size() - 1;
	if (pas > size) {
		return false;
	}
	if (c.dim() == 0) {
		return false;
	}
	return true;
}