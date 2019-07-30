#pragma once
#include <string>

using std::string;

class Produs {
private:
	int id;
	string nume;
	string tip;
	double pret;

public:

	/*Constructor produs*/
	Produs(int id, string nume, string tip, double pret) :
		id{ id }, nume{ nume }, tip{ tip }, pret{ pret } {
	}

	/*Functie ce returneaza id ul produsului*/
	int getId() const {
		return this->id;

	}

	/*Functie ce returneaza numele produsului*/
	string getNume() const {
		return this->nume;
	}

	/*Functie ce returneaza tipul produsului*/
	string getTip() const {
		return this->tip;
	}

	/*Functie ce returneaza pretul produsului*/
	double getPret() const {
		return this->pret;
	}

};