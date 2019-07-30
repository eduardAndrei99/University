#include "Simulareee.h"
#include <QtWidgets/QApplication>
#include "produs.h"
#include "UiProdus.h"
#include "service.h"
#include "repo.h"
#include <vector>

void testAll() {
	testProdus();
	testFiltru();
}

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	testAll();
	Repo rep{ "produse.txt" };
	Service srv{ rep };
	UiProdus ui{ srv };
	/*
	Produs p{ "z",1,true };
	std::vector<Produs>v;
	v.push_back(p);
	ui.reloadList(v);
	*/
	/*
	std::ofstream out("debug.txt");
	std::vector<Produs>v = rep.getAll();
	out << v.size();
	*/
	
	ui.show();

	return a.exec();
}
