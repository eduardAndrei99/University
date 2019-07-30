#include "UiGUI.h"
#include <algorithm>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <string>
#include <qdebug.h>
#include "export.h"

void ConsoleGui::init() {
	QVBoxLayout* vL = new QVBoxLayout;
	setLayout(vL);

	//adaug lista si sub doua butoane de sort
	QWidget* widDreapta = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout;
	widDreapta->setLayout(vl);
	list = new QTableWidget(10,1);
	vl->addWidget(list);

	QWidget* widBtnDreapta = new QWidget;
	QHBoxLayout* lyBtnsDr = new QHBoxLayout;
	widBtnDreapta->setLayout(lyBtnsDr);
	this->sortByTitle = new QPushButton("Sort by title");
	lyBtnsDr->addWidget(this->sortByTitle);
	this->sortByDescription = new QPushButton("Sort description");
	lyBtnsDr->addWidget(sortByDescription);
	this->sortTipTime = new QPushButton("SortTip&Time");
	lyBtnsDr->addWidget(sortTipTime);
	vL->addWidget(widDreapta);
	vL->addWidget(widBtnDreapta);
	this->undoButton = new QPushButton("&Undo");
	this->modificareButton = new QPushButton("&Modifica");
	this->cosButton = new QPushButton("&Cos de activitati");
	this->filtreButton = new QPushButton("&Filtre");
	QWidget* down = new QWidget;
	QVBoxLayout* lyDown = new QVBoxLayout;
	down->setLayout(lyDown);
	lyDown->addWidget(undoButton);
	lyDown->addWidget(modificareButton);
	lyDown->addWidget(cosButton);
	lyDown->addWidget(filtreButton);
	vL->addWidget(down);

	//DETAIL
	QWidget* details = new QWidget;
	QFormLayout* fL = new QFormLayout;
	details->setLayout(fL);
	QLabel* lblTitle = new QLabel("Titlu");
	txtTitle = new QLineEdit;
	fL->addRow(lblTitle, txtTitle);
	QLabel* lblType = new QLabel("Tip");
	txtType = new QLineEdit;
	fL->addRow(lblType, txtType);
	QLabel* lblDescriere = new QLabel("Descriere");
	txtDescriere = new QLineEdit;
	fL->addRow(lblDescriere, txtDescriere);
	QLabel* lblDurata = new QLabel("Durata");
	txtDurata = new QLineEdit;
	fL->addRow(lblDurata, txtDurata);
	vL->addWidget(details);
	store = new QPushButton("&Store");
	remove = new QPushButton("&Remove");
	vL->addWidget(store);
	vL->addWidget(remove);
}

void ConsoleGui::addActivity() {
	try {
		this->srv.add(txtTitle->text().toStdString(), txtDescriere->text().toStdString(), txtType->text().toStdString(), txtDurata->text().toInt());
		//ctr.add(txtType->text().toStdString(), txtSpecies->text().toStdString(), txtPrice->text().toDouble());
		//reloadList(ctr.getAllPets());
		reloadList(srv.getAll());
	}
	catch (ValidateException&) {
		QMessageBox::warning(this, "Warning","Nu e bine ");
	}
	catch (RepoERROR&) {
		QMessageBox::warning(this, "Warning", "Mai exista unul ");
	}
}

void ConsoleGui::connectSignalsSlots() {
	QObject::connect(store, &QPushButton::clicked, this, &ConsoleGui::addActivity);
	
	QObject::connect(sortByTitle, &QPushButton::clicked, this, [&]() {
		reloadList(this->srv.sortareTitlu());
	});

	QObject::connect(sortByDescription, &QPushButton::clicked, this, [&]() {
		reloadList(this->srv.sortareDescriere());
	});

	QObject::connect(sortTipTime, &QPushButton::clicked, this, [&]() {
		reloadList(this->srv.sortareTipSiDurata());
	});

	QObject::connect(modificareButton, &QPushButton::clicked, this, [&]() {
		/*
		QLineEdit* txtTitle;
		QLineEdit* txtType;
		QLineEdit* txtDescriere;
		QLineEdit* txtDurata;
		*/
		QString titlu = this->txtTitle->text();
		QString descriere = this->txtDescriere->text();
		QString type = this->txtType->text();
		QString durata = this->txtDurata->text();
		try {
			srv.deleteActivity(titlu.toStdString());
		} 
		catch (StergereERROR&) {
			QMessageBox::warning(this, "Warning", "!!! ");
		}
		try {
			srv.add(titlu.toStdString(), descriere.toStdString(), type.toStdString(), durata.toInt());
		}
		catch (ValidateException&) {
			QMessageBox::warning(this, "Warning", "!!! ");
		}
		reloadList(srv.getAll());
	});

	QObject::connect(cosButton, &QPushButton::clicked, this, [&]() {
		QWidget* widgetCos = new QWidget();
		widgetCos->setWindowTitle("Cos Activitati");
		QFormLayout* lay = new QFormLayout;
		cos = new QListWidget;
		widgetCos->setLayout(lay);
		lay->addWidget(cos);
		adaugaListaButton = new QPushButton("&Adauga in lista");
		QLabel* lblRandom = new QLabel("Random:");
		txtRandom = new QLineEdit;
		randomInListaButton = new QPushButton("&Random");
		lay->addRow(lblRandom, txtRandom);
		lay->addWidget(randomInListaButton);
		golesteListaButton = new QPushButton("&Goleste lista");
		lay->addWidget(adaugaListaButton);
		lay->addWidget(golesteListaButton);
		QLabel* lblCVS = new QLabel("CVS file : ");
		QLabel* lblHtml = new QLabel("HTML file :");
		exportCvsButton = new QPushButton("Export CVS");
		exportHtmlButton = new QPushButton("Export Html");
		txtExportCvs = new QLineEdit;
		txtExportHtml = new	QLineEdit;
		lay->addRow(lblCVS,txtExportCvs);
		lay->addWidget(exportCvsButton);
		lay->addRow(lblHtml, txtExportHtml);
		lay->addWidget(exportHtmlButton);
		connectSignalCos();
		widgetCos->show();
	});

	QObject::connect(undoButton, &QPushButton::clicked, this, [&]() {
		try {
			this->srv.undo();
		}
		catch (RepoERROR& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
		}
		reloadList(this->srv.getAll());
	});

	QObject::connect(list, &QTableWidget::itemSelectionChanged,this, [&]() {
		if (this->list->selectedItems().isEmpty()) {
			this->txtDurata->setText("");
			this->txtType->setText("");
			this->txtDescriere->setText("");
			this->txtTitle->setText("");
			return;
		}
		QTableWidgetItem* selItem = list->selectedItems().at(0);
		QString titlu = selItem->text();
		Activity act = srv.cautaActivitate(titlu.toStdString());
		this->txtTitle->setText(titlu);
		this->txtDurata->setText(QString::number(act.getTime()));
		this->txtDescriere->setText(QString::fromStdString(act.getDescription()));
		this->txtType->setText(QString::fromStdString(act.getType()));

	});

	QObject::connect(remove, &QPushButton::clicked, this, [&]() {
		QString titlu = this->txtTitle->text();
		try {
			srv.deleteActivity(titlu.toStdString());
		}
		catch (StergereERROR&) {
			QMessageBox::warning(this, "Warning", "Selectati ceva ! ");
		}
		reloadList(srv.getAll());
	});
	
	QWidget::connect(filtreButton, &QPushButton::clicked, [&]() {
		QWidget* widgetFiltre = new QWidget;
		QFormLayout* ly = new QFormLayout;
		widgetFiltre->setLayout(ly);
		this->txtDescriereFiltru = new QLineEdit;
		this->txtTipFiltru = new QLineEdit;
		QLabel* lblDescFiltru = new QLabel("Descriere");
		QLabel* lblTipFiltru = new QLabel("Tip");
		this->filtruDescButton = new QPushButton("FiltrareDescriere");
		this->filtruTipButton = new QPushButton("FiltrareTip");
		ly->addRow(lblDescFiltru, txtDescriereFiltru);
		ly->addWidget(filtruDescButton);
		ly->addRow(lblTipFiltru, txtTipFiltru);
		ly->addWidget(filtruTipButton);
		listaFiltre = new QListWidget;
		ly->addWidget(listaFiltre);
		connectSignalFiltre();
		widgetFiltre->setWindowTitle("Filtre");
		widgetFiltre->show();
	});

}

void ConsoleGui::connectSignalCos() {
	QWidget::connect(adaugaListaButton, &QPushButton::clicked, [&]() {
		QString title = txtTitle->text();
		QString type = txtType->text();
		QString descriere = txtDescriere->text();
		QString durata = txtDurata->text();
		this->srv.adaugaInListaService(title.toStdString());
		reloadCos(this->srv.getLista());
	});

	QWidget::connect(golesteListaButton, &QPushButton::clicked, [&]() {
		this->srv.golesteListaService();
		reloadCos(this->srv.getLista());
	});

	QWidget::connect(randomInListaButton, &QPushButton::clicked, [&]() {
		this->srv.randomService(txtRandom->text().toUInt());
		reloadCos(this->srv.getLista());
	});
	
	QWidget::connect(exportCvsButton, &QPushButton::clicked, [&]() {
		QString numeF = txtExportCvs->text();
		exportToCVS(numeF.toStdString(), this->srv.getAll());
	});

	QWidget::connect(exportHtmlButton, &QPushButton::clicked, [&]() {
		QString numeF = txtExportHtml->text();
		exportToHTML(numeF.toStdString(), this->srv.getAll());
	});

}

void ConsoleGui::reloadList(const std::vector<Activity>& acts) {
	auto colorize = srv.getAll();
	list->clear();
	int i = 0;
	for (const auto& act : acts) {
		QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(act.getTitle()));
		if (act.getTime() >= 10) {
			item->setBackgroundColor(QColor{ Qt::red });
			//item->setBackground(Qt::red);
		}
		list->setItem(0, i++, item);
		//list->setItem(0, i++, new QTableWidgetItem(QString::fromStdString(act.getTitle())));
		//QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(act.getTitle()), list);
		//item->setData(Qt::UserRole, QString::fromStdString(act.getType()));//adaug in lista (invizibil) si type 
		//if (std::find(colorize.cbegin(), colorize.cend(), p) !=colorize.end()){//merge pt ca am adaugat operator== la Pet		
			//item->setBackground(QBrush{ QColor{Qt::red},Qt::CrossPattern });		
			//item->setBackgroundColor(QColor{ Qt::red });
		//}
	}
}

void ConsoleGui::reloadCos(activitatiCurente& acts) {
	const std::vector<Activity>& activitati = acts.getLista();
	cos->clear();
	for (const auto& act : activitati) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(act.getTitle()), cos);
	}
}

void ConsoleGui::reloadListaFiltre(const std::vector<Activity>& acts) {
	auto colorize = srv.getAll();
	listaFiltre->clear();
	for (const auto& act : acts) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(act.getTitle()), listaFiltre);
		item->setData(Qt::UserRole, QString::fromStdString(act.getType()));//adaug in lista (invizibil) si type 
		//if (std::find(colorize.cbegin(), colorize.cend(), p) !=colorize.end()){//merge pt ca am adaugat operator== la Pet		
			//item->setBackground(QBrush{ QColor{Qt::red},Qt::CrossPattern });		
			//item->setBackgroundColor(QColor{ Qt::red });
		//}
	}
}

void ConsoleGui::connectSignalFiltre() {

	QObject::connect(filtruDescButton, &QPushButton::clicked, [&]() {
		QString desc = this->txtDescriereFiltru->text();
		reloadListaFiltre(this->srv.filtrareDescriereServ(desc.toStdString()));
		//reloadListaFiltre(this->srv.getAll());
	});

	QObject::connect(filtruTipButton, &QPushButton::clicked, [&]() {
		QString tip = this->txtTipFiltru->text();
		reloadListaFiltre(this->srv.filtrareTipServ(tip.toStdString()));
	});
}