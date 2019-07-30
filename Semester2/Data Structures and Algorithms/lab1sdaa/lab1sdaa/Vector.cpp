#include "Vector.h"

void Vector:: resize() {
	int newSize = 2 * this->maxSize;
	this->maxSize = newSize;
	TElem* x = new TElem[newSize];

	for (int i = 0; i < currentSize; i++) {
		x[i] = elems[i];
	}
	delete(this->elems);
	this->elems = x;
}

void Vector::push_back(TElem x) {
	if (this->currentSize == this->maxSize - 1) {
		resize();
	}

	this->elems[currentSize++] = x;
}
