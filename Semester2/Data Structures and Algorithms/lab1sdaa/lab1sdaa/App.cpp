#include <iostream>
#include "Matrice.h"
#include <assert.h>
#include "Vector.h"

using namespace std;

void testCreeaza() {
	Matrice m(10, 10);
	assert(m.nrLinii() == 10);
	assert(m.nrColoane() == 10);
	for (int i = 0; i < m.nrLinii(); i++)
		for (int j = 0; j < m.nrColoane(); j++)
			assert(m.element(i, j) == NULL_TELEMENT);
}

void testAdauga() {
	Matrice m(10, 10);
	for (int j = 0; j < m.nrColoane(); j++)
		m.modifica(4, j, 3);
	for (int i = 0; i < m.nrLinii(); i++)
		for (int j = 0; j < m.nrColoane(); j++)
			if (i == 4)
				assert(m.element(i, j) == 3);
			else
				assert(m.element(i, j) == NULL_TELEMENT);
}

void testQuantity() {//scopul e sa adaugam multe date
	Matrice m(720, 720);
	for (int i = 0; i < m.nrLinii(); i++)
		for (int j = 0; j < m.nrColoane(); j++)
			if (i % 2 == 0 && j % 2 == 0)
				m.modifica(i, j, i*j);
			else
				if (j % 3 == 0)
					m.modifica(i, j, i + j);
	for (int i = 0; i < m.nrLinii(); i++)
		for (int j = 0; j < m.nrColoane(); j++)
			if (i % 2 == 0 && j % 2 == 0)
				assert(m.element(i, j) == i * j);
			else
				if (j % 3 == 0)
					assert(m.element(i, j) == i + j);
				else assert(m.element(i, j) == 0);

}

void testExceptii() {
	Matrice m(10, 10);
	try {
		m.element(-1, -1);
	}
	catch (exception&) {
		assert(true); //ar trebui sa arunce exceptie
	}
	try {
		m.modifica(12, 0, 1);
	}
	catch (exception&) {
		assert(true); //ar trebui sa arunce exceptie
	}
	try {
		assert(m.nrLinii());
	}
	catch (exception&) {
		assert(false); //nu ar trebui sa arunce exceptie
	}
}

void testScurt() {
	Matrice m(4, 4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modifica(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEMENT);
}

void testAllExtins() {
	testCreeaza();
	testAdauga();
	testQuantity();
	testExceptii();
	testScurt();
}

int main() {

	testAllExtins();

	return 0;
}