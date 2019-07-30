#pragma once

typedef int TElem;

class Vector {
	int currentSize;
	int maxSize;
	TElem* elems;
public:
	
	Vector() {
		this->elems = new TElem[2];
		for (int i = 0; i < maxSize; i++) {
			elems[i] = 0;
		}
		this->maxSize = 2;
		this->currentSize = 0;
	}

	void setSize(int size) {
		TElem* X = elems;
		elems = new TElem[size];
		delete(X);
		maxSize = size;
		for (int i = 0; i < maxSize; i++) {
			elems[i] = 0;
		}
	}

	void resize();

	void push_back(TElem x);

	TElem &operator [](int i) const{
		return elems[i];
	}

	int getSize() {
		return this->currentSize;
	}

	void scadUnu() {
		this->currentSize--;
	}
};


