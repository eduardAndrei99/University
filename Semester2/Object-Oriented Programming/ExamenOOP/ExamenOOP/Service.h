#pragma once
#include "repository.h"
#include "validator.h"
#include <algorithm>

class Service {
private:
	Repo& repo;
	Validator& val;
public:
	/*Constructor
	primeste un repo si un validator
	se creeaza un service
	*/
	Service(Repo& repo, Validator& val) : repo{ repo }, val{ val } {
	}

	/*
	Nu pot copia service
	*/
	Service(const Service& ot) = delete;

	/*
	Iau toate produsele din repo asa cum sunt
	*/
	const vector<Produs>& getAllFromRepo() const {
		return this->repo.getAll();
	}

	/*
	Returnez lista cu produsele sortate
	*/
	const vector<Produs> getAllSorted() const {
		vector<Produs>v = this->getAllFromRepo();
		std::sort(v.begin(), v.end(), [&](const Produs& p1, const Produs &p2) {
			return p1.getPret() < p2.getPret();
		});
		return v;
	}


	/*
	Adaug element in service
	daca elementul valid si nu mai exista
	unul in repo cu acelasi id
	se adauga cu succes
	daca nu : arunca exceptia potrivita
	*/
	void adaugaService(int id, string nume, string tip, double pret);

};