#pragma once
#include "Activity.h"
#include "ActivityRepo.h"

class ActiuneUndo {
public:
	//Metoda pur virtuala
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
	Activity actAdaugata;
	ActivityRepo& rep;
public:
	UndoAdauga(ActivityRepo& rep, 
		const Activity& actAdaugata) :
		rep{ rep }, actAdaugata{ actAdaugata } {
	}

	void doUndo() override {
		rep.deleteRepo(actAdaugata);
	}
};

class UndoSterge : public ActiuneUndo {
	Activity actStearsa;
	ActivityRepo& rep;
public:
	UndoSterge(ActivityRepo& rep, const Activity& actStearsa) :
		rep{ rep }, actStearsa{ actStearsa } {
	}
	
	void doUndo() override {
		rep.store(actStearsa);
	}
};

class UndoModifica : public ActiuneUndo {
	Activity actModificata;
	ActivityRepo& rep;
	size_t poz;
public:
	UndoModifica(ActivityRepo& rep, const Activity& actModificata, size_t poz) : rep{ rep }, 
		actModificata{ actModificata }, poz{ poz } {
	}

	void doUndo() override {
		rep.modificaRepo(actModificata, poz);
	}

};