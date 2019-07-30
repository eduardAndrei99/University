#include "UiProdus.h"
#include "qcolor.h"
#include "qbrush.h"

void UiProdus::constuiesc() {
	this->list = new QListWidget;
	QVBoxLayout* ly = new QVBoxLayout;
	setLayout(ly);
	ly->addWidget(list);
	toateButton = new QPushButton("&Toate");
	filtrareButton = new QPushButton("&Filtrare");
	ly->addWidget(toateButton);
	ly->addWidget(filtrareButton);
}

void UiProdus::reloadList(vector<Produs>& all) {
	list->clear();
	for (const auto& p : all) {
		std::string s;
		s += p.getNume();
		s += ' ';
		if (p.getCumparat() == true) {
			s += '1';
		}
		else {
			s += '0';
		}
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(s), list);
		int cantitate = p.getCantitate();
		if (cantitate == 1) {
			item->setBackgroundColor(Qt::green);
		}
		else if (cantitate >= 5) {
			item->setBackgroundColor(Qt::red);
		}
		list->addItem(item);
	}
}

void UiProdus::signalsButoane() {

	QObject::connect(this->filtrareButton, &QPushButton::clicked, [&]() {
		this->reloadList(this->srv.getFiltru());
	});


	QObject::connect(this->toateButton, &QPushButton::clicked, [&]() {
		this->reloadList(this->srv.getAll());
	});

}