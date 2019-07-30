#pragma once
#include "ActivityRepo.h"
#include "validator.h"
#include <string.h>
#include <functional>
#include <algorithm>
#include "activitatiCurente.h"
#include "undo.h"
#include <vector>

class Service {
private:
	ActivityRepo& repo;
	ActivityValidator& val;
	vector<Activity> filtreaza(function<bool(const Activity&)>fct) const;
	typedef bool(*MaiMicF)(const Activity&, const Activity&);
	vector<Activity>& generalSort(MaiMicF maiMicF);
	activitatiCurente lista;
	std::vector<ActiuneUndo*> undoList;

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

	/*sortari dupa criterii*/
	vector<Activity>& sortareDescriere();
	vector<Activity>& sortareTitlu();
	vector<Activity>& sortareTipSiDurata();
	/*
	iau raportuu cu map*/
	std::string getRaport();

	/*adaug in lista de acctivitati*/

	void adaugaInListaService(std::string title);
	/*
	umplu lista random*/
	void randomService(size_t cate);

	/*golesc lista*/
	void golesteListaService();

	/*undoo*/
	void undo();

	/*destructor*/
	~Service() {
		while (undoList.empty() == false) {
			ActiuneUndo* del = undoList.back();
			undoList.pop_back();
			delete del;
		}
	}

};

