#pragma once
#include "Activity.h"
#include <vector>
#include "exceptii.h"
#include <algorithm>
#include <fstream>

using std::vector;

class ActivityRepo {
private:
	std::vector<Activity> all;

public:
	ActivityRepo() = default;

	virtual ~ActivityRepo() = default;

	ActivityRepo(const ActivityRepo& ot) = delete;//nu vreau sa se copieze repo

	/*
	adauga o activitate in repo
	*/
	virtual void store(const Activity& act) {

		//verificam sa nu mai existe un pet 
		auto found = std::find_if(all.begin(), all.end(), [act](const Activity& pp) {
			return pp.getTitle() == act.getTitle();
		});
		if (found != all.end()) {
			throw RepoERROR{ "Mai exista unul \n" };
		}
		all.push_back(act);
	}
	
	/*
	return un vector de activitati
	*/
	std::vector<Activity>& getAll() noexcept {
		return this->all;
	}

	/*
	modific o activitate in repo pe pozitia poz*/
	void modificaRepo(Activity act, const size_t poz);

	/*
	caut o activitate dupa titlu*/
	Activity find(const std::string title);

	/*
	sterg o activitate*/
	virtual void deleteRepo(const Activity& act);
};

class ActivityRepoFile :public ActivityRepo{
private:
	std::string fName;
	void loadFromFile();
	void writeToFile();
public:
	ActivityRepoFile(std::string fName) :ActivityRepo(), fName{ fName } {
		loadFromFile();//incarcam datele din fisier
	}
	/*
	adaug in repo*/
	void store(const Activity& act) override {
		ActivityRepo::store(act);//apelam metoda din clasa de baza
		writeToFile();
	}

	/*
	sterg din repo*/
	void deleteRepo(const Activity& act) override {
		ActivityRepo::deleteRepo(act);//apelam metoda din clasa de baza
		writeToFile();
	}
};

