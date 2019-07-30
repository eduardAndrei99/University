#pragma once
#include "Service.h"
#include <qwidget.h>
#include <qtablewidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qslider.h>

class UiProdus : public QWidget {
private:
	QTableWidget* tabel;
	QLabel* labelId;
	QLabel* labelNume;
	QLabel* labelTip;
	QLabel* labelPret;
	QLineEdit* linieId;
	QLineEdit* linieNume;
	QLineEdit* linieTip;
	QLineEdit* liniePret;
	QPushButton* adaugaButton;
	QSlider* slider;
	/*
	Construiesc interfata grafica
	*/
	void construire();

	/*
	Incarc produsele in tabel
	*/
	void reloadTable(const vector<Produs> all);

	/*
	Conectez semnalele
	*/
	void connectSignal();
	Service& srv;

public :
	/*
	Constructor
	primeste service
	conecteaza toate
	*/
	UiProdus(Service& srv) : srv{ srv } {
		construire();
		reloadTable(this->srv.getAllSorted());
		connectSignal();
	}
};
