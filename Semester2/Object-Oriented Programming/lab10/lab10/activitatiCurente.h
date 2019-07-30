#pragma once

#include <vector>
#include "Activity.h"
#include <chrono>
#include <random>
using std::vector;
using namespace std;

class activitatiCurente {
private:
	vector<Activity> lista;

public:

	/*
	constructor default*/
	activitatiCurente() = default;

	/*
	functie ce goleste lista de activitati*/
	void golesteLista() noexcept{
		lista.clear();
	}

	/*
	adauga o activitate in lista*/
	void adauga(const Activity& act) noexcept{
		lista.push_back(act);
	}

	/*
	get lista activitati*/
	const vector<Activity>& getLista() const noexcept{
		return this->lista;
	}

	/*umplu aleator lista cu act*/
	void umple(size_t cate, vector<Activity> all) {
		this->golesteLista();
		std::shuffle(all.begin(), all.end(), std::default_random_engine(std::random_device{}())); //amesteca vectorul v
		while (lista.size() < cate && all.size() > 0) {
			lista.push_back(all.back());
			all.pop_back();
		}
	}

};
