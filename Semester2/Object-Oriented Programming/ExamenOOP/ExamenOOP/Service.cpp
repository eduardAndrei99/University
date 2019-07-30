#include "Service.h"

void Service::adaugaService(int id, string nume, string tip, double pret) {
	Produs p{ id,nume,tip,pret };
	this->val.validate(p);
	this->repo.addRepo(p);
}