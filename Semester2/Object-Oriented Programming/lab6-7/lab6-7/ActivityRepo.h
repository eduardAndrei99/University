#pragma once
#include "Activity.h"
#include <vector>

class ActivityRepo {
private:
	std::vector<Activity> all;

public:
	ActivityRepo() = default;

	/*
	adauga o activitate in repo
	*/
	void addRepo(const Activity& act);
	
	/*
	return un vector de activitati
	*/
	std::vector<Activity>& getAll() noexcept {
		return this->all;
	}

};

