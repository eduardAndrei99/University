#pragma once
#include <string>

class Produs {
private:
	std::string nume;
	int cantitate;
	bool cumparat;

public:
	/*
	Constructor
	*/
	Produs(std::string nume, int cantitate, bool cumparat)
		:nume{ nume }, cantitate{ cantitate }, cumparat{ cumparat } {
	}

	/*Get name*/
	std::string getNume() const{
		return this->nume;
	}

	/*Get cantitate*/
	int getCantitate() const {
		return this->cantitate;
	}

	/*Get cumparat*/
	bool getCumparat() const {
		return this->cumparat;
	}

};

void testProdus();