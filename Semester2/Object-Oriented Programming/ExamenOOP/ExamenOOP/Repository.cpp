#include "repository.h"

void Repo::loadFromFile() {
	string nume;
	string tip;
	int id;
	double pret;
	std::ifstream in(this->numeF);
	while (in >> id >> nume >> tip >> pret) {
		Produs p{ id,nume,tip,pret };
		this->all.push_back(p);
	}
}

void Repo::addRepo(const Produs& p) {
	for (auto prod : this->all) {
		if (prod.getId() == p.getId()) {
			throw RepoError{ "2 id la fel!\n" };
		}
	}
	this->all.push_back(p);
}