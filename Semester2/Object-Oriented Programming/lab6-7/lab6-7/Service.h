#pragma once
#include "ActivityRepo.h"
#include "validator.h"
#include <string.h>
#include <functional>
#include <algorithm>
#include "activitatiCurente.h"

class Service {
private:
	ActivityRepo& repo;
	ActivityValidator& val;
	vector<Activity> filtreaza(function<bool(const Activity&)>fct) const;
	typedef bool(*MaiMicF)(const Activity&, const Activity&);
	vector<Activity>& generalSort(MaiMicF maiMicF);
	activitatiCurente lista;

public:
	activitatiCurente& getLista() {
		return this->lista;
	}

	/*
	PetStore(PetRepo& rep, PetValidator& val) noexcept:rep{ rep }, val{ val } {
	}*/
	Service(ActivityRepo& repo, ActivityValidator& val) noexcept :repo{ repo }, val{ val } {
	}
	
	/*
	 adauga o activitate
	*/
	void add(std::string, std::string, std::string, int);

	/*
	 returneaza toate activitatile in ordinea in care au fost adaugate
	*/
	vector<Activity>& getAll() const noexcept {
		return repo.getAll();
	}

	/*
	 modifica activitatea de pe pozitia poz
	*/
	void modifica(const string title, const string description, const string type, const int time, const size_t poz);

	/*
	 filtreaza dupa descriere
	*/
	vector<Activity> filtrareDescriereServ(string desc) const;

	/*
	 filtreaza dupa tip
	*/
	vector<Activity> filtrareTipServ(string tip) const;

	/*
	 sterge activitatea title
	*/
	void deleteActivity(string title);

	/*
	 cauta o activitate
	*/
	Activity cautaActivitate(const string title);

	/*
	 sortari
	*/
	vector<Activity>& sortareDescriere();
	vector<Activity>& sortareTitlu();
	vector<Activity>& sortareTipSiDurata();
	std::string getRaport();
	void adaugaInListaService(std::string title);
	void randomService(size_t cate);
	void golesteListaService();

};

