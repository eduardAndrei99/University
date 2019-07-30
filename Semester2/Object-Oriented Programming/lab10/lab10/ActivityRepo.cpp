#include "ActivityRepo.h"
using std::vector;

void ActivityRepo::modificaRepo(Activity act, size_t poz) {
	this->all.at(poz) = act;
}

Activity ActivityRepo::find(const std::string title) {
	std::vector<Activity>::iterator it = std::find_if(all.begin(), all.end(),
		[title](Activity& act) {
		return act.getTitle() == title; });
	if (it != all.end()) {
		return *it;
	}
	throw CautaERROR{};}

void ActivityRepoFile::loadFromFile() {
	std::ifstream in(fName);
	if (!in.is_open()) { //verify if the stream is opened		
		throw RepoERROR("Unable to open file:" + fName);
	}
	while (!in.eof()) {
		std::string title;
		in >> title;
		std::string type;
		in >> type;
		std::string description;
		in >> description;

		int price;
		in >> price;
		if (in.eof()) {	//nu am reusit sa citesc numarul
			break;
		}
		Activity act{ title.c_str(), type.c_str(), description.c_str(),price };
		//Pet p{ type.c_str(), species.c_str(), price };
		//PetRepo::store(p);
		try {
			ActivityRepo::store(act);
		}
		catch (RepoERROR&) {}
	}
	in.close();
}

void ActivityRepoFile::writeToFile() {
	std::ofstream out(fName);
	for (auto& p : getAll()) {
		out << p.getTitle();
		out << std::endl;
		out << p.getType();
		out << std::endl;
		out << p.getDescription();
		out << std::endl;
		out << p.getTime();
		out << std::endl;
	}
	out.close();
}

void ActivityRepo::deleteRepo(const Activity& act) {
	vector<Activity>::iterator it = all.begin();
	for (const auto& other : all) {
		if (other.getTitle() == act.getTitle()) {
			all.erase(it);
			return;
		}
		it++;
	}
	throw StergereERROR{};
}