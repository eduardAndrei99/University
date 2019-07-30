#include "Ui.h"
#include "qboxlayout.h"
#include "qmessagebox.h"

void UiProdus::construire() {

	QHBoxLayout* layH = new QHBoxLayout;
	QVBoxLayout* lay = new QVBoxLayout;
	tabel = new QTableWidget;
	labelId = new QLabel("Id");
	labelNume = new QLabel("Nume");
	this->labelPret = new QLabel("Pret");
	this->labelTip = new QLabel("Tip");
	this->linieId = new QLineEdit;
	this->linieNume = new QLineEdit;
	this->liniePret = new QLineEdit;
	this->linieTip = new QLineEdit;
	this->adaugaButton = new QPushButton("Add");
	this->slider = new QSlider;
	slider->setRange(1, 100);
	slider->setValue(50);
	lay->addWidget(tabel);
	lay->addWidget(adaugaButton);
	lay->addWidget(labelId);
	lay->addWidget(linieId);
	lay->addWidget(labelNume);
	lay->addWidget(linieNume);
	lay->addWidget(labelTip);
	lay->addWidget(linieTip);
	lay->addWidget(labelPret);
	lay->addWidget(liniePret);
	layH->addLayout(lay);
	//layH->addWidget(slider);
	this->setLayout(layH);
}

void UiProdus::reloadTable(const vector<Produs> all) {
	
	this->tabel->setRowCount(all.size());
	this->tabel->setColumnCount(5);
	int linie = 0;
	double prag = this->slider->value();
	for (const auto& el : all) {
			string idS = std::to_string(el.getId());
			QTableWidgetItem* itemId = new QTableWidgetItem(QString::fromStdString(idS));
			QTableWidgetItem* itemNume = new QTableWidgetItem(QString::fromStdString(el.getNume()));
			QTableWidgetItem* itemTip = new QTableWidgetItem(QString::fromStdString(el.getTip()));
			string pretS = std::to_string(el.getPret());
			QTableWidgetItem* itemPret = new QTableWidgetItem(QString::fromStdString(pretS));
			if (el.getPret() <= prag) {
				//itemId->setBackgroundColor(Qt::red);
				//itemNume->setBackgroundColor(Qt::red);
				//itemTip->setBackgroundColor(Qt::red);
				//itemPret->setBackgroundColor(Qt::red);
			}
			tabel->setItem(linie, 0, itemId);
			tabel->setItem(linie, 1, itemNume);
			tabel->setItem(linie, 2, itemTip);
			//string pretS = std::to_string(el.getPret());
			tabel->setItem(linie, 3, itemPret);
			/*
			tabel->setItem(linie, 0, new QTableWidgetItem(QString::fromStdString(idS)));
			tabel->setItem(linie, 1, new QTableWidgetItem(QString::fromStdString(el.getNume())));
			tabel->setItem(linie, 2, new QTableWidgetItem(QString::fromStdString(el.getTip())));
			string pretS = std::to_string(el.getPret());
			tabel->setItem(linie, 3, new QTableWidgetItem(QString::fromStdString(pretS)));
			*/
			int vocale = 0;
			auto nume = el.getNume();
			for (const auto& x : nume) {
				if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
					++vocale;
				}
			}
			string vocaleS = std::to_string(vocale);
			tabel->setItem(linie, 4, new QTableWidgetItem(QString::fromStdString(vocaleS)));
			linie++;
	}
}

void UiProdus::connectSignal() {

	QWidget::connect(adaugaButton, &QPushButton::clicked, [&]() {
		int id = this->linieId->text().toInt();
		string nume = this->linieNume->text().toStdString();
		string tip = this->linieTip->text().toStdString();
		string Eroare;
		double pret = this->liniePret->text().toDouble();
		try {
			this->srv.adaugaService(id, nume, tip, pret);
		}
		catch (MyException& ex) {
			QMessageBox msg;
			Eroare += ex.getErori();
			//msg.setText(QString::fromStdString(ex.getErori()));
			for (const auto el : this->srv.getAllFromRepo()) {
				if (el.getId() == id) {
					Eroare += "Id folosit\n";
				}
			}
			msg.setText(QString::fromStdString(Eroare));
			msg.exec();
		}
		catch (RepoError& er) {
			QMessageBox msg;
			msg.setText(QString::fromStdString(er.getError()));
			msg.exec();
		}
		this->reloadTable(this->srv.getAllSorted());
	});

	QWidget::connect(slider, &QSlider::valueChanged, [&]() {
		this->reloadTable(this->srv.getAllSorted());
	});

}