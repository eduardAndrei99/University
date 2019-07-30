#include "CP.h"
#include <algorithm>

bool CP::existLeftSon(int poz) {
	return (3 * poz + 1 <= this->currentSize - 1);
}

bool CP::existMiddleSon(int poz) {
	return (3 * poz + 2 <= this->currentSize - 1);
}

bool CP::existRightSon(int poz) {
	return (3 * poz + 3 <= this->currentSize - 1);
}

bool CP::root(int poz) {
	return (poz == 0);
}

int CP::leftSon(int poz) {
	return (3 * poz + 1);
}

int CP::middleSon(int poz) {
	return(3 * poz + 2);
}

int CP::rightSon(int poz) {
	return (3 * poz + 3);
}

int CP::parent(int poz) {
	return (poz - 1) / 3;
}

void CP::swap(Element& e1, Element& e2) {
	Element e3{ e1.first, e1.second };
	e1.first = e2.first;
	e1.second = e2.second;
	e2.first = e3.first;
	e2.second = e3.second;
}

void CP::urca(Element el, int poz) {
	while (poz != 0 && this->r(el.second, elems[parent(poz)].second)) {
		Element e1 = el;
		Element e2 = elems[parent(poz)];
		swap(e1, e2);
		elems[parent(poz)] = e2;
		elems[poz] = e1;
		poz = (poz - 1) / 3;
	}
}

void CP::coboara(Element el, int poz) {
	int pozitieBuna = -1;
	while (true) {

		pozitieBuna = -1;
		int valoareStanga = INT_MAX;
		int valoareMijloc = INT_MAX;
		int valoareDreapta = INT_MAX;
		bool amJos = false;

		if (existLeftSon(poz)) {
			valoareStanga = elems[leftSon(poz)].second;
			amJos = true;
		}

		if (existMiddleSon(poz)) {
			valoareMijloc = elems[middleSon(poz)].second;
			amJos = true;
		}

		if (existRightSon(poz)) {
			valoareDreapta = elems[rightSon(poz)].second;
			amJos = true;
		}

		if (amJos == false) {
			return;
		}

		int minim = std::min(std::min(valoareStanga, valoareMijloc), valoareDreapta);
		int nodMinim = -1;
		if (minim == valoareStanga) {
			nodMinim = this->leftSon(poz);
		}
		if (minim == valoareMijloc) {
			nodMinim = this->middleSon(poz);
		}
		if (minim == valoareDreapta) {
			nodMinim = this->rightSon(poz);
		}

		//in nodMinim am cea mai smechera valoare
		if (r(elems[nodMinim].second, elems[poz].second)) {
			pozitieBuna = nodMinim;
		}

		if (pozitieBuna == -1) {
			return;
		}

		Element e1 = elems[pozitieBuna];
		Element e2 = elems[poz];
		swap(e1, e2);
		elems[pozitieBuna] = e1;
		elems[poz] = e2;
		poz = pozitieBuna;
	}
}