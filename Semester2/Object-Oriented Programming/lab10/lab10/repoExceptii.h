#pragma once

#include "ActivityRepo.h"
#include <stdlib.h>
#include <time.h>
#include <string>

class ProbabilityERROR {
public:
	ProbabilityERROR(std::string mesaj) noexcept :
		message(mesaj) {
	}
	const std::string& getMessage() const noexcept {
		return message;
	}
private:
	std::string message;
};

class ProbabilityRepo: public ActivityRepo{
	double pr;
public:
	ProbabilityRepo(double pr) : pr{ pr } {
	}

	void store(const Activity& act) override {
		const int val = rand() % 100;
		if (val < pr * 100)
		{
			std::string s = "Probabilitate mica";
			throw ProbabilityERROR(s);
		}
		ActivityRepo::store(act);
	}
};