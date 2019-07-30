#pragma once
#include "domain.h"
#include <exception>

class MyException {
	string eroare;
public:
	/*
	Constructor
	param: string eroare
	eroarea
	post, se creeaza un obiect myException
	*/
	MyException(string eroare) : eroare{ eroare } {
	}

	/*
	Returneaza erorile din exceptie
	*/
	string getErori() {
		return this->eroare;
	}
};

class Validator {
public:
	Validator() = default;

	/*
	Validarea unui produs
	*/
	bool validate(const Produs& p) {
		string error;
		if (p.getNume() == "") {
			error += "Nume gol\n";
		}
		if (p.getPret() > 100 || p.getPret() < 1) {
			error += "Pret incorect\n";
		}
		if (error.size() == 0) {
			return true;
		}
		throw MyException{ error };
	}

	/*
	Nu pot copia validatorul
	*/
	Validator(const Validator& ot) = delete;
};
