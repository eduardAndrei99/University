#include "validator.h"

void ActivityValidator::validate(const Activity& act) {
	vector<string>msg;
	if (act.getDescription() == "") {
		msg.push_back("Descriere goala\n");
	}
	if (act.getTime() <= 0) {
		msg.push_back("Durata nu poate fi negativa\n");
	}
	if (act.getTitle() == "") {
		msg.push_back("Titlu gol\n");
	}
	if (act.getType() == "") {
		msg.push_back("Tip gol\n");
	}
	if (msg.size() > 0) {
		throw ValidateException(msg);
	}
}
