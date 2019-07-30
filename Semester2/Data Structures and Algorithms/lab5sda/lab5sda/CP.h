#pragma once

#include <iostream>
#include <exception>
//CP.h

using std::cout;
typedef int TElem;
typedef int TPrioritate;

typedef std::pair<TElem, TPrioritate> Element;

typedef bool(*Relatie)(TPrioritate ,TPrioritate);
class CP {
private:
	/* aici e reprezentarea */
	Relatie r;
	Element* elems;
	int maxSize;
	int currentSize;

public:
	//constructorul implicit
	CP(Relatie r) :r{ r } {
		maxSize = 10;
		elems = new Element[10];
		currentSize = 0;
	}
	
	void aux() {
		std::cout << "Current Size = " << currentSize << "\n";
		for (int i = 0; i < currentSize; i++) {
			std::cout << elems[i].second << " ";
		}
		std::cout << std::endl;
	}

	bool existLeftSon(int poz);
	bool existMiddleSon(int poz);
	bool root(int poz);
	bool existRightSon(int poz);
	int leftSon (int poz);
	int middleSon (int poz);
	int rightSon (int poz);
	void swap(Element& el1, Element& el2);
	void urca(Element el, int poz);
	int parent(int poz);

	//adauga un element in CP, avand o anumita pioritate
	void adauga(TElem e, TPrioritate p) {
		if (this->vida()) {
			Element el{ e,p };
			elems[0] = el;
			++currentSize;
			return;
		}
		if (currentSize == maxSize - 1) {
			redimensionare();
		}
		Element elDeAdaugat{ e,p };
		this->elems[currentSize] = elDeAdaugat;
		currentSize++;
		urca(elDeAdaugat, currentSize - 1);
	}

	void redimensionare() {
		int newSize = 2 * this->maxSize;
		Element* newElems = new Element[newSize];
		for (int i = 0; i < maxSize; i++) {
			newElems[i] = elems[i];
		}
		maxSize = newSize;
		delete[] elems;
		elems = newElems;
	}


	//acceseaza elementul cel mai prioritar in raport cu relatia de ordine 
	//arunca exceptie daca CP e vida
	Element element()  const {
		if (this->vida()) {
			throw std::exception("");
		}
		else {
			return elems[0];
		}
	}

	void coboara(Element el, int poz);

	//sterge elementul cel mai prioritar si il returneaza
	//arunca exceptie daca CP e vida
	Element sterge() {
		if (this->vida()) {
			throw std::exception("");
		}
		Element x = this->elems[0];
		this->elems[0] = this->elems[this->currentSize-1];
		--currentSize;
		coboara(elems[0], 0);
		return x;
	}

	//verifica daca CP e vida;
	bool vida() const {
		if (this->currentSize == 0) {
			return true;
		}
		return false;
	}


	// destructorul cozii
	~CP() = default;

};
