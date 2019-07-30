#pragma once

#include "Activity.h"
#include <iostream>
#include <vector>

using namespace std;

class ValidateException {
	vector<string> msgs;
public:
	ValidateException(const vector<string>& errors) :msgs{ errors } {}
	//functie friend (vreau sa folosesc membru privat msg)
	friend ostream& operator<<(ostream& out, const ValidateException& ex);
};


class ActivityValidator {
public:
	void validate(const Activity& act);
};
