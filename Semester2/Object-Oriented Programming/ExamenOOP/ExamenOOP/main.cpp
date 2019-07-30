#include "ExamenOOP.h"
#include <QtWidgets/QApplication>
#include "teste.h"
#include "domain.h"
#include "repository.h"
#include "Service.h"
#include "Ui.h"

void testAll() {
	testEntitate();
	testValidare();
	testAdd();
}

int main(int argc, char *argv[]) {

	testAll();
	QApplication a(argc, argv);
	
	Repo rep{ "produse.txt" };
	Validator v;
	Service srv{ rep,v };
	UiProdus ui(srv);
	ui.show();


	return a.exec();
}
