#pragma once
#include "repo.h"


class Service {
private:
	Repo rep;

public:
	/*Constructor*/
	Service(Repo rep) : rep{ rep } {
	}
	
	/*Le iau pe toate*/
	vector<Produs>& getAll() {
		return this->rep.getAll();
	}

	/*Le fitlrez*/
	vector<Produs> getFiltru() {
		return this->rep.getFiltru();
	}

};

void testFiltru();