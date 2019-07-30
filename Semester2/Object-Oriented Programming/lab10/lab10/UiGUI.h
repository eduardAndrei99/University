#pragma once
#include "Service.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include "activity.h"
#include <vector>
#include <qlabel.h>
#include "activitatiCurente.h"

class ConsoleGui : public QWidget{
private:
	Service& srv;
	QListWidget* list;
	QListWidget* cos;
	QListWidget* listaFiltre;
	QPushButton* store;
	QPushButton* remove;
	QPushButton* sortByTitle;
	QLineEdit* txtTitle;
	QLineEdit* txtType;
	QLineEdit* txtRandom;
	QLineEdit* txtDescriere;
	QLineEdit* txtDurata;
	QLineEdit* txtDescriereFiltru;
	QLineEdit* txtTipFiltru;
	QLineEdit* txtExportCvs;
	QLineEdit* txtExportHtml;
	QPushButton* sortByDescription;
	QPushButton* sortTipTime;
	QPushButton* filtreButton;
	QPushButton* undoButton;
	QPushButton* modificareButton;
	QPushButton* cosButton;
	QPushButton* adaugaListaButton;
	QPushButton* randomInListaButton;
	QPushButton* golesteListaButton;
	QPushButton* filtruDescButton;
	QPushButton* filtruTipButton;
	QPushButton* exportCvsButton;
	QPushButton* exportHtmlButton;
	void init();
	void connectSignalsSlots();
	void reloadList(const std::vector<Activity>& acts);
	void reloadCos(activitatiCurente& acts);
	void addActivity();
	void connectSignalCos();
	void connectSignalFiltre();
	void reloadListaFiltre(const std::vector<Activity>& acts);
public:
	ConsoleGui(Service srv) : srv{ srv } {
		init();
		connectSignalsSlots();
		reloadList(srv.getAll());
	}
};