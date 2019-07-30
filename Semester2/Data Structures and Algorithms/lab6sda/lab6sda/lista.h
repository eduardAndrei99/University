#pragma once
#include <vector>
using std::vector;
typedef int TValoare;

typedef struct nodValori {
	TValoare info;
	nodValori* urm;
	nodValori* prec;
}nodValori;

class listaValori {
private:
	nodValori* cap = new nodValori();

public:

	listaValori() {
		this->cap = nullptr;
	}

	~listaValori() {

	}

	/*
	Functie ce adauga o valoarea in lista dublu inlantuita de valori
	Returneaza valoarea adaugata
	*/
	TValoare addValoare(TValoare val) {
		if (this->cap == nullptr) {
			nodValori* nou = new nodValori();
			nou->info = val;
			nou->prec = nullptr;
			nou->urm = nullptr;
			cap = nou;
		}
		else {
			nodValori* nou = new nodValori();
			nou->info = val;
			nou->prec = nullptr;
			nou->urm = this->cap;
			this->cap->prec = nou;
			cap = nou;
		}
		return val;
	}

	TValoare &operator [](int i) {
		int contor = 0;
		nodValori* head = this->cap;
		for (; contor < i; contor++) {
			head = head->urm;
		}
		return head->info;
	}

	int size() {
		int size = 0;
		if (cap == nullptr) {
			return 0;
		}
		if (cap->urm == nullptr) {
			return 1;
		}
		nodValori* head = this->cap;
		while (head != nullptr) {
			size++;
			head = head->urm;
		}
		return size;
	}

	/*
	Functie ce sterge valoarea val
	Returneaza true daca s a sters
	False daca nu
	*/
	bool stergeValoare(TValoare val) {
		nodValori* head = this->cap;
		if (head == nullptr) {
			return false;
		}
		for (int i = 0; i < this->size(); i++) {
			if (head->info == val) {
				nodValori* precedent = head->prec;
				nodValori* urmator = head->urm;
				if (precedent == nullptr && urmator == nullptr) {
					this->cap = nullptr;
					return true;
				}
				if (precedent == nullptr) {
					this->cap = urmator;
					this->cap->prec = nullptr;
					return true;
				}
				if (urmator == nullptr) {
					nodValori* node = head->prec;
					node->urm = nullptr;
					delete head;
					return true;
				}
				precedent->urm = urmator;
				urmator->prec = precedent;
				delete head;
				return true;
			}
			head = head->urm;
		}
		return false;
	}

};