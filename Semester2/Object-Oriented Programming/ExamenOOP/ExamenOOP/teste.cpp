#include "teste.h"
#include <fstream>
#include "repository.h"
#include "Service.h"

void testEntitate() {
	Produs p{ 1,"nume","tip",100.5 };
	assert(p.getId() == 1);
	assert(p.getNume() == "nume");
	assert(p.getTip() == "tip");
	assert(p.getPret() == 100.5);
}

void testValidare() {
	Validator v;
	Produs p{ 3,"","type",12 };
	try {
		v.validate(p);
	}
	catch (MyException& e) {
		assert(e.getErori().size() > 0);
	}

	Produs p1{ 1,"dad","type2",19999 };
	try {
		v.validate(p);
	}
	catch (MyException& e) {
		assert(e.getErori().size() > 0);
	}

	Produs p2{ 1,"da","da",50 };
	bool ok = v.validate(p2);
	assert(ok);
}

void testAdd() {
	Repo rep{ "test.txt" };
	Validator v;
	Service srv{ rep,v };
	assert(srv.getAllFromRepo().size() == 0);
	srv.adaugaService(1, "lapte", "aliment", 3.2);
	assert(srv.getAllFromRepo().size() == 1);
	try {
		srv.adaugaService(1, "lapte", "aliment", 3);
	}
	catch (RepoError& ex) {
		assert(ex.getError().size());
	}
	try {
		srv.adaugaService(2, "", "da", 1000);
	}
	catch (MyException& ex) {
		assert(ex.getErori().size());
	}

}