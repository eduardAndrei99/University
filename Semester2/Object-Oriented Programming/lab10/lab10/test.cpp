#pragma once

#include <iostream>
#include "test.h"
#include "exceptii.h"
#include "export.h"
#include <fstream>
#include "repoExceptii.h"

void testGet() {
	Activity a1{ "plimbare", "frumoasa","recreere", 123 };
	assert(a1.getTitle() == "plimbare");
	assert(a1.getDescription() == "frumoasa");
	assert(a1.getType() == "recreere");
	assert(a1.getTime() == 123);
	Activity a2{ "", "", "", -231 };
	Activity a3{a1};
	assert(a3.getTitle() == "plimbare");
	assert(a3.getDescription() == "frumoasa");
	assert(a3.getType() == "recreere");
	assert(a3.getTime() == 123);
}

void testAdd() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service service{ repo, val };
	//Console console{ service };
	service.add("act1", "act2", "Act3", 321);
	assert(service.getAll().size() == 1);
	try {
		service.add("act1", "act2", "Act3", 321);}
	catch (RepoERROR& ex) {
		assert(ex.getMessage().at(0) == 'M');
	}
}

void testValidare() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service service{ repo, val };
	//Activity act{ "","","",-2 };
	try {
		service.add("", "", "", -2);}
	catch (ValidateException& ) {
		assert(true);
	}
}

void testModificare() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service service{ repo, val };
	service.add("act1", "act2", "Act3", 321);
	service.modifica("bbb", "bbb", "bbb", 3, 0);
	std::vector<Activity>& all = service.getAll();
	assert(all.at(0).getTime() == 3);
	try {
		service.modifica("bbb", "bbb", "bbb", 3, 3);}
	catch (const ModificaERROR& er) {
		string x = er.getMessage();
		assert(x.at(0) == 'M');
	}
}

void testStergere() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service service{ repo, val };
	service.add("act1", "act2", "Act3", 321);
	service.deleteActivity("act1");
	const std::vector<Activity>& all = service.getAll();
	assert(all.size()==0);
	try {
		service.deleteActivity("act1");}
	catch (const StergereERROR& er) {
		string m = er.getMessage();
		assert(m.at(0) == 'S');
	}
	service.add("act1", "act2", "Act3", 321);
	service.add("act3", "act2", "Act3", 321);
	service.deleteActivity("act3");
	assert(all.size() == 1);
}

void testCauta() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service service{ repo, val };
	service.add("act1", "act2", "Act3", 321);
	Activity act = service.cautaActivitate("act1");
	assert(act.getTime() == 321);
	try {
		act = service.cautaActivitate("dsadsada");}
	catch (const CautaERROR& er) {
		string m = er.getMessage();
		assert(m.at(0) == 'N');
	}

}

void testFiltrare() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service serv{ repo, val };
	serv.add("act1", "act2", "Act3", 321);
	serv.add("volei", "plaja", "sport", 123);
	serv.add("fotbal", "sala", "sport", 132);
	serv.add("baschet", "teren", "sport", 20);
	vector<Activity> filtru = serv.filtrareTipServ("sport");
	assert(filtru.at(0).getTime() == 123);
	assert(filtru.size() == 3);
	filtru = serv.filtrareDescriereServ("plaja");
	assert(filtru.at(0).getTime() == 123);
	assert(filtru.size() == 1);
}

void testSort() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service serv{ repo, val };
	serv.add("act1", "act2", "Act3", 321);
	serv.add("volei", "plaja", "sport", 123);
	serv.add("fotbal", "sala", "sport", 132);
	serv.add("baschet", "teren", "sport", 20);
	vector<Activity>& sorted = serv.sortareDescriere();
	assert(sorted.at(0).getTime() == 321);
	sorted = serv.sortareTitlu();
	assert(sorted.at(1).getTime() == 20);
	sorted = serv.sortareTipSiDurata();
	assert(sorted.at(1).getTime() == 20);
	assert(sorted.at(3).getTime() == 132);
}

void testMap() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service serv{ repo, val };
	serv.add("act1", "act2", "Act3", 321);
	serv.add("volei", "plaja", "sport", 123);
	serv.add("fotbal", "sala", "sport", 132);
	serv.add("baschet", "teren", "sport", 20);
	std::string rez = serv.getRaport();
	assert(rez == "sport");
	ActivityRepo repo2{};
	ActivityValidator val2;
	Service serv2{ repo2, val2 };
	std::string rez2 = serv2.getRaport();
	assert(rez2 == "Nu sunt");
}

void testLista() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service serv{ repo, val };
	serv.add("act1", "act2", "Act3", 321);
	serv.add("volei", "plaja", "sport", 123);
	serv.add("fotbal", "sala", "sport", 132);
	serv.add("baschet", "teren", "sport", 20);
	serv.randomService(3);
	assert(serv.getLista().getLista().size() == 3);
	serv.golesteListaService();
	assert(serv.getLista().getLista().size() == 0);
	serv.adaugaInListaService("act1");
	assert(serv.getLista().getLista().size() == 1);
	serv.adaugaInListaService("adsa");
	assert(serv.getLista().getLista().size() == 1);
}

void testExport() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service serv{ repo, val };
	serv.add("act1", "act2", "Act3", 321);
	serv.add("volei", "plaja", "sport", 123);
	serv.add("fotbal", "sala", "sport", 132);
	serv.add("baschet", "teren", "sport", 20);
	exportToCVS("testCVS", serv.getAll());
	std::ifstream in("testCVS");
	string s;
	in >> s;
	assert(s.at(0) == 'a');
	assert(s.at(3) == '1');
	exportToHTML("testHTML", serv.getAll());
	std::ifstream inh("testHTML");
	string sh;
	for (int i = 1; i <= 4; i++) {
		std::getline(inh, sh);
	}
	assert(sh.at(5) == 'c');
}

void testFisiere() {
	std::ofstream out("testAct.txt", std::ios::trunc);
	out.close();//creez un fisier gol
	ActivityRepoFile repF{ "testAct.txt" };
	repF.store(Activity{ "aaa","bbb","ccc", 12 });
	ActivityRepoFile repF2{ "testAct.txt" };
	auto p = repF2.find("aaa");
	assert(p.getTime() == 12);
	repF2.deleteRepo(Activity{ "aaa","bbb","ccc", 12 });

	try {
		repF2.deleteRepo(Activity{ "aaa","bbb","ccc", 12 });}
	catch (StergereERROR& ex) {
		assert(ex.getMessage().at(0) == 'S');
	}

	try {
		auto w = repF2.find("aaa");}
	catch (CautaERROR& er) {
		assert(er.getMessage().at(0) == 'N');}

	try {
		repF.store({ "aaa","bbb","ccc",12 });}
	catch (RepoERROR& ex) {
		assert(ex.getMessage().at(0) == 'M');
	}
	try {
		ActivityRepoFile repF3{ "dsada" };}
	catch (RepoERROR& ex) {
		assert(ex.getMessage().at(0) == 'U');
	}
	
}

void testUndo() {
	ActivityRepo repo{};
	ActivityValidator val;
	Service serv{ repo, val };
	serv.add("act1", "act2", "Act3", 321);
	serv.add("volei", "plaja", "sport", 123);
	serv.add("fotbal", "sala", "sport", 132);
	serv.add("baschet", "teren", "sport", 20);
	assert(serv.getAll().size() == 4);
	serv.undo();
	assert(serv.getAll().size() == 3);
	serv.deleteActivity("volei");
	assert(serv.getAll().size() == 2);
	serv.undo();
	assert(serv.getAll().size() == 3);
	//Activity act = serv.getAll().at(0);
	//std::cout << act.getTitle();
	serv.modifica("ed", "ed", "ed", 100, 0);
	serv.undo();
	assert(serv.getAll().at(0).getTitle().at(0) == 'a');
	ActivityRepo repo2{};
	ActivityValidator val2;
	Service serv2{ repo2, val2 };
	try {
		serv2.undo();
	}
	catch (RepoERROR&) {

	}
}

void testRepoError() {
	ProbabilityRepo repo{ 1 };
	//ActivityRepoFile repo{ "activitati.txt" };
	ActivityValidator val;
	Service service{ repo, val };
	Console console{ service };
	try {
		service.add("dsada", "Adsad", "Adsa", 23);
	}
	catch (ProbabilityERROR& ex) {
		std::string msj = ex.getMessage();
		assert(msj.at(0) == 'P');
	}

	ProbabilityRepo repo2{ 0 };
	//ActivityRepoFile repo{ "activitati.txt" };
	ActivityValidator val2;
	Service service2{ repo2, val2 };
	Console console2{ service2 };
	service2.add("dsada", "Adsad", "Adsa", 23);
}