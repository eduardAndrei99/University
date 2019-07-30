#pragma once

#include <vector>
using std::vector;
typedef int TCheie;
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

typedef struct nodChei {
	TCheie cheie;
	listaValori valori;
	nodChei* urm;
	nodChei* prec;
}nodChei;

class listaChei {
private:
	nodChei* cap = new nodChei();

public:
	
	listaChei() {
		this->cap = nullptr;
	}

	~listaChei() {

	}

	void add(TCheie cheie, TValoare valoare) {
		if (this->cap == nullptr) {
			nodChei* nou = new nodChei();
			nou->urm = nullptr;
			nou->prec = nullptr;
			nou->cheie = cheie;
			listaValori l;
			l.addValoare(valoare);
			nou->valori = l;
			this->cap = nou;
			return;
		}
		nodChei* head = this->cap;
		while (head != nullptr) {
			if (head->cheie == cheie) {
				head->valori.addValoare(valoare);
				return;
			}
			head = head->urm;
		}
		if (head == nullptr) {
			nodChei* nou = new nodChei();
			nou->cheie = cheie;
			nou->prec = nullptr;
			nou->urm = this->cap;
			this->cap->prec = nou;
			listaValori l;
			l.addValoare(valoare);
			nou->valori = l;
			this->cap = nou;
		}
		return;
	}

	int size() const{
		if (this->cap == nullptr) {
			return 0;
		}
		if (this->cap->urm == nullptr) {
			return 1;
		}
		nodChei* head = cap;
		int size = 0;
		while (head != nullptr) {
			size++;
			head = head->urm;
		}
		return size;
	}

	TCheie &operator [](int i) {
		int contor = 0;
		nodChei* head = this->cap;
		for (; contor < i; contor++) {
			head = head->urm;
		}
		return head->cheie;
	}

	vector<TValoare> cauta(TCheie cheie) const {
		vector<TValoare>aux;
		nodChei* itChei = this->cap;
		for (; itChei != nullptr; itChei = itChei->urm) {
			if (itChei->cheie == cheie) {
				for (int j = 0; j < itChei->valori.size(); j++) {
					aux.push_back(itChei->valori[j]);
				}
			}
		}
		return aux;
	}

	/*
	Functie ce sterge valoarea val
	Returneaza true daca s a sters
	False daca nu
	*/
	bool stergeCheie(TCheie val) {
		nodChei* head = this->cap;
		if (head == nullptr) {
			return false;
		}
		for (int i = 0; i < this->size(); i++) {
			if (head->cheie == val) {
				nodChei* precedent = head->prec;
				nodChei* urmator = head->urm;
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
					nodChei* node = head->prec;
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

	bool stergeCheieValoare(TCheie cheie, TValoare valoare) {
		nodChei* head = this->cap;
		for (; head != nullptr; head = head->urm) {
			if (head->cheie == cheie) {
				bool ret = head->valori.stergeValoare(valoare);
				if (head->valori.size() == 0) {
					this->stergeCheie(cheie);
				}
				return ret;
			}
		}
		return false;
	}

	bool vid() const{
		return this->size() == 0;
	}

	int dim() const {
		if (this->cap == nullptr) {
			return 0;
		}
		int d = 0;
		nodChei* it = this->cap;
		for (; it != nullptr; it = it->urm) {
			d += it->valori.size();
		}
		return d;
	}

	int dimListaCheie(int pozitie) const{
		nodChei* it = this->cap;
		int i = 0;
		while (i != pozitie) {
			it = it->urm;
			i++;
		}
		return it->valori.size();
	}

	nodChei* getHead() const{
		return this->cap;
	}

};