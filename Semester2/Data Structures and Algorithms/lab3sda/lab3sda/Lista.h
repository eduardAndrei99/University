#pragma once

#include <iostream>

typedef struct pereche {
	int numar;
	int frecventa;
}pereche ;

typedef int TElem;

class Node {
private:
	pereche key;
	Node *prev;
	Node *next;
public:
	Node() {}

	void set_key(pereche x) {
		key = x;
	}

	void set_prev(Node *x) {
		prev = x;
	}

	void set_next(Node *x) {
		next = x;
	}

	pereche &get_key() {
		return this->key;
	}

	Node *get_prev() {
		return this->prev;
	}

	Node *get_next() {
		return this->next;
	}
};

class Lista {
private:
	Node *head = new Node();
public:
	Lista() {
		//head->set_key(0);
		head->set_prev(nullptr);
		head->set_next(nullptr);
	}

	void insert(pereche x) {
		// Insertion done at front of the list
		Node *n = new Node();
		n->set_key(x);
		n->set_next(head->get_next());
		if (head->get_next() != nullptr)
			(head->get_next())->set_prev(n);
		head->set_next(n);
		n->set_prev(nullptr);
	}

	void print_nodes() {
		Node *x = head->get_next();
		while (x != nullptr) {
			pereche y = x->get_key();
			std::cout << y.numar << " " << y.frecventa << " " << std::endl;
			x = x->get_next();
		}
	}

	int size() const{
		Node *x = head->get_next();
		int contor = 0;
		while (x != nullptr) {
			//pereche y = x->get_key();
			//std::cout << y.numar << " " << y.frecventa << " " << std::endl;
			x = x->get_next();
			contor++;
		}
		return contor;
	}

	pereche &operator [](int i) {
		Node *x = head->get_next();
		int contor = 0;
		while (contor != i) {
			x = x->get_next();
			contor++;
		}
		return x->get_key();
	}
};