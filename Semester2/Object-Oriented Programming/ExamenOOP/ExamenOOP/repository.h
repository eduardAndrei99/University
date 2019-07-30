#pragma once
#include <vector>
#include "domain.h"
#include <fstream>
using std::vector;

class RepoError {
	string error;
public:
	/*Constructor, primeste ca parametru
	string : error
	*/
	RepoError(string error) : error{ error } {
	}

	/*Returneaza eroarea : string*/
	string getError() const {
		return this->error;
	}
};

class Repo {
private:
	vector<Produs>all;
	string numeF;

public:
	/*Construieste un repo cu numele de fisier*/
	Repo(string numeF) : numeF{ numeF } {
		loadFromFile();
	}

	/*Returneaza lista cu produse*/
	const vector<Produs>& getAll() const{
		return this->all;
	}

	/*Incarca datele din fisier*/
	void loadFromFile();

	/*Nu pot copia repo*/
	Repo(const Repo& ot) = delete;

	/*Adaug in repo un produs*/
	void addRepo(const Produs& p);

};
