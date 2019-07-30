#pragma once
#include <fstream>
#include <vector>
#include <string>
using std::vector;
using std::string;
#include "produs.h"

class Repo {
private:
	string numeF;
	vector<Produs> all;

public:
	Repo(string numeF) : numeF{ numeF } {
		loadFromFile();
	}

	void loadFromFile() {
		//all.clear();
		std::ifstream in(numeF);
		string name;
		int cant;
		bool cump;
		
		while (in >> name >> cant >> cump) {
			Produs p{ name, cant, cump };
			all.push_back(p);
		}
		
	}

	vector<Produs>&getAll() {
		return this->all;
	}

	vector<Produs> getFiltru() {
		std::vector<Produs> v;
		for (const auto& p : this->all) {
			if (p.getCumparat() == 0) {
				v.push_back(p);
			}
		}
		return v;
	}

};