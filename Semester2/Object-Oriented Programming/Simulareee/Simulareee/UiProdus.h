#pragma once
#include "service.h"
#include "qwidget.h"
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qboxlayout.h>

class UiProdus : public QWidget{
private:

	//aici butoanele si alea
	Service srv;
	QPushButton* toateButton;
	QPushButton* filtrareButton;
	QListWidget* list;

public:
	UiProdus(Service srv) : srv{ srv } {
		this->constuiesc();
		reloadList(this->srv.getAll());
		signalsButoane();
	}

	/*Pun elementele*/
	void constuiesc();

	/*reload in lista*/
	void reloadList(vector<Produs>& all);

	/*conectez signals*/
	void signalsButoane();

};
