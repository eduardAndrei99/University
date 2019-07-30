#include "Service.h"
#include <algorithm>
#include "exceptii.h"
#include <unordered_map>

void Service::add(std::string titlu, std::string des, std::string tip, int durata) {
	// titlu, descriere, tip, durata
	Activity act{ titlu, des, tip, durata };
	val.validate(act);
		
	repo.store(act);
	this->undoList.push_back(new UndoAdauga{ this->repo, act });
}


void Service::modifica(const string title, const string description, const string type, const int time, const size_t poz) {
	std::vector<Activity>& all = repo.getAll();
	const size_t dim = all.size();
	if (poz + 1 > dim || poz < 0) {
		throw ModificaERROR{};
	}

	Activity a = Activity{ title, description, type, time };
	val.validate(a);
	Activity deMod = Activity{ all.at(poz).getTitle(),all.at(poz).getType(),
	all.at(poz).getDescription(), all.at(poz).getTime() };
	this->undoList.push_back(new UndoModifica{ this->repo, deMod, poz });
	this->repo.modificaRepo(a, poz);
	//all.at(poz) = a;
}

void Service::deleteActivity(string title) {
	vector<Activity>& all = getAll();

	for (size_t i = 0; i < all.size(); i++) {
		if (all[i].getTitle() == title) {
			Activity act{ all[i].getTitle(), all[i].getType(), all[i].getDescription(), all[i].getTime() };
			this->undoList.push_back(new UndoSterge{ repo, act });
			repo.deleteRepo(all[i]);
			return;
		}
	}
	Activity act{ "sadasdas"," dsadsadas", "Dsadsadsa", 123 };
	repo.deleteRepo(act);}
	/*
	vector<Activity>::iterator it = all.begin();
	for (const auto& other : all) {
		if (other.getTitle() == title) {
			all.erase(it);
			return;
		}
		it++;
	}
	throw StergereERROR{};
	*/

void Service::undo() {
	if (this->undoList.empty()) {
		throw RepoERROR("No more undo\n");
	}
	ActiuneUndo* act = this->undoList.back();
	act->doUndo();
	undoList.pop_back();
	delete act;
		/*
		act->doUndo();
	undoActions.pop_back();
	delete act;
	*/
}

Activity Service::cautaActivitate(const string title) {
	//vector<Activity>& all = getAll();
	/*
	vector<Activity>::iterator it = all.begin();
	for (const auto& other : all) {
		if (other.getTitle() == title) {
			Activity good{ other };
			return good;
		}
		it++;
	}
	throw 0; 
	*/
	return this->repo.find(title);
}

vector<Activity> Service::filtreaza(function<bool(const Activity&)> fct) const {
	vector<Activity> all = repo.getAll();
	vector<Activity> rez(all.size());
	
	/*
	for (const auto& pet : repo.getAll()) {
		if (fct(pet)) {
			rez.push_back(pet);
		}
	}
	*/
	
	auto it = std::copy_if(all.begin(), all.end(), rez.begin(), fct);
	rez.resize(std::distance(rez.begin(), it));

	return rez;
}

vector<Activity> Service::filtrareDescriereServ(string desc) const{
	return filtreaza([desc](const Activity& act)  {
		if (act.getDescription().find(desc) == -1) {
			return false;
		}
		return true;
	});
}

vector<Activity> Service::filtrareTipServ(string desc) const {
	return filtreaza([desc](const Activity& act)  {
		if (act.getType().find(desc) == -1) {
			return false;
		}
		return true;
	});
}

vector<Activity>& Service::generalSort(MaiMicF maiMicF) {
	vector<Activity>& v = { repo.getAll() };
	sort(v.begin(), v.end(), maiMicF);
	return v;
}

vector<Activity>& Service::sortareDescriere() {
	return generalSort([](const Activity& act1, const Activity& act2) {
		return act1.getDescription() < act2.getDescription();
	});
}

vector<Activity>& Service::sortareTitlu() {
	return generalSort([](const Activity& act1, const Activity& act2) {
		return act1.getTitle() < act2.getTitle();
	});
}

vector<Activity>& Service::sortareTipSiDurata() {
	return generalSort([](const Activity& act1, const Activity& act2) {
		if (act1.getType() == act2.getType()) {
			return act1.getTime() < act2.getTime();
		}
		return act1.getType() < act2.getType();
	});
}

std::string Service::getRaport() {
	vector<Activity> all = repo.getAll();
	std::unordered_map<std::string, int> map;
	for (auto x : all) {
		map.insert(make_pair(x.getTitle(), 0));
	}

	for (auto x : all) {
		map[x.getType()] += 1;
	}

	int maxim = 0;
	for (auto x : map) {
		if (x.second > maxim) {
			maxim = x.second;
		}
	}

	for (auto x : map) {
		if (x.second == maxim) {
			return x.first;
		}
	}
	return "Nu sunt";
}

void Service::adaugaInListaService(std::string title) {
	//vector<Activity>& all = repo.getAll();
	try {
		Activity act = cautaActivitate(title);
		this->lista.adauga(act);
	}
	catch (CautaERROR&){
		return;}
}

void Service::randomService(size_t cate) {
	this->lista.umple(cate, this->getAll());
}

void Service::golesteListaService() {
	this->getLista().golesteLista();
}