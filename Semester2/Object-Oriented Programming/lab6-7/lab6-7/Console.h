#pragma once

#include "Service.h"
#include <string>
#include <iostream>
#include <vector>

class Console {
private:
	Service &serv;

public:
	Console(Service& serv) noexcept :serv{ serv } {
	};

	/*
	Citeste datele de la tastatura si adauga activitate
	arunca exceptie daca: nu se poate salva, nu e valid
	*/
	void adaugaUI();

	/*
	Afiseaza meniul
	*/	
	void printUi();

	/*
	start ui
	*/
	void start();

	/*
	printeaza toate activitatile
	*/
	void printAll(vector<Activity>& all) const;

	/*
	modifica o activitate
	*/
	void modificaUi();

	/*
	sterge o activitate
	*/
	void deleteUi();

	/*
	adauga cateva activitati
	*/
	void addCateva();

	/*
	cauta o activitate
	*/
	void cautaActivitate();

	/*
	filtraza dupa descriere
	*/
	void filtrareDescriere();

	/*
	filtreaza dupa tip
	*/
	void filtrareTip();

	/*
	raportul
	*/
	void raportUi();
	
	void adaugaInListaUi();

	void afiseazaLista() const;

	void golesteLista();

	void randomUi();

	void exportCvsUi();

	void exportHtmlUi();

};

