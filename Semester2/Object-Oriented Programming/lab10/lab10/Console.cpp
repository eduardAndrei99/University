#include "Console.h"
#include "exceptii.h"
#include <unordered_map>
#include "export.h"
#include "repoExceptii.h"

using std::cout;
using std::cin;

void Console::adaugaUI() {
	// titlu, descriere, tip, durata
	std::string title;
	std::string description;
	std::string type;
	int time;
	std::cout << "Titlul ";
	std::cin >> title;
	std::cout << "Descriere ";
	std::cin >> description;
	std::cout << "Tip ";
	std::cin >> type;
	std::cout << "Timp ";
	std::cin >> time;
	serv.add(title, description, type, time);
	cout << "Adaugat cu succes\n";
}

void Console::addCateva() {
	serv.add("trezit", "dimineata", "ceva", 10);
	serv.add("mancat", "seara", "ceva", 12);
	serv.add("volei", "plaja", "sport", 123);
	serv.add("fotbal", "sala", "sport", 132);
	serv.add("baschet", "teren", "sport", 20);
	serv.add("mic", "dejun", "mancare", 12312);
	serv.add("cina", "mare", "friptura", 20);
}

void Console::printUi() {
	cout << std::endl;
	cout << "Menu\n";
	cout << "[1] Adaug \n";
	cout << "[2] Afisare\n";
	cout << "[3] Modificare\n";
	cout << "[4] Stergere \n";
	cout << "[5] Cauta activitate \n";
	cout << "[6] Filtrare descriere \n";
	cout << "[7] Filtrare tip \n";
	cout << "[8] Sortare titlu \n";
	cout << "[9] Sortare descriere \n";
	cout << "[10] Sortare tip + durata \n";
	cout << "[11] Raport UI cu map \n";
	cout << "[12] Afiseaza lista \n";
	cout << "[13] Adauga in lista\n";
	cout << "[14] Random in lista\n";
	cout << "[15] Goleste lista\n";
	cout << "[16] Export in cvs\n";
	cout << "[17] Export in html\n";
	cout << "[18] Undo \n";
	cout << "[0] Exit\n";
}

void::Console::modificaUi() {
	size_t number{};
	std::cout << "Pozitia : ";
	std::cin >> number;
	if (cin.fail()) {
		return;
	}
	// titlu, descriere, tip, durata
	std::string title;
	std::string description;
	std::string type;
	int time;
	std::cout << "Titlul ";
	std::cin >> title;
	std::cout << "Descriere ";
	std::cin >> description;
	std::cout << "Tip ";
	std::cin >> type;
	std::cout << "Timp ";
	std::cin >> time;
	serv.modifica(title, description, type, time, number);
}

void Console::printAll(vector<Activity>& all) const{
	for (const auto& act : all) {
		cout << act.getTitle() << " " << act.getDescription() << " " << act.getType() << " ";
		cout << " " << act.getTime() << std::endl;
	}
}

void Console::deleteUi() {
	cout << "Introduceti titlul de sters ";
	string title{};
	cin >> title;
	try {
		serv.deleteActivity(title);
		//cout << "Sters.\n";
	}
	catch (const StergereERROR& er) {
		cout << er.getMessage();
	}
}

void Console::cautaActivitate() {
	cout << "Introduceti titlul activitatii ";
	string title{};
	cin >> title;
	try {
		Activity act = serv.cautaActivitate(title);
		cout << act.getTitle() << " " << act.getDescription() << " " << act.getType() << " ";
		cout << " " << act.getTime() << std::endl;
	}
	catch (const CautaERROR& er ) {
		cout << er.getMessage();
	}
}

void Console::filtrareDescriere() {
	cout << "Descriere :";
	string desc;
	cin >> desc;
	vector<Activity> vectorFiltrat = serv.filtrareDescriereServ(desc);
	for (auto act : vectorFiltrat) {
		cout << act.getTitle() << " " << act.getDescription() << " " << act.getType() << " ";
		cout << " " << act.getTime() << std::endl;
	}
}

void Console::filtrareTip() {
	cout << "Tip :";
	string desc;
	cin >> desc;
	vector<Activity> vectorFiltrat = serv.filtrareTipServ(desc);
	for (auto act : vectorFiltrat) {
		cout << act.getTitle() << " " << act.getDescription() << " " << act.getType() << " ";
		cout << " " << act.getTime() << std::endl;
	}
}

void Console::raportUi() {
	std::string tipMult= serv.getRaport();
	cout << tipMult << "\n";
}

void Console::adaugaInListaUi() {
	string title{};
	cin >> title;
	serv.adaugaInListaService(title);
}

void Console::afiseazaLista() const{
	activitatiCurente act = serv.getLista();
	vector<Activity> all = act.getLista();
	for (const auto& actt : all) {
		cout << actt.getTitle() << " " << actt.getDescription() << " " << actt.getType() << " ";
		cout << " " << actt.getTime() << std::endl;
	}
}

void Console::golesteLista() {
	this->serv.golesteListaService();
}

void Console::randomUi() {
	size_t number;
	cout << "Introduceti numaru de activitati \n";
	cin >> number;
	if (cin.fail()) {
		return;
	}
	serv.randomService(number);
}

void Console::exportCvsUi() {
	string numeF;
	cin >> numeF;
	exportToCVS(numeF, this->serv.getAll());
}

void Console::exportHtmlUi() {
	string numeF;
	cin >> numeF;
	exportToHTML(numeF, this->serv.getAll());
}

void Console::undoUi() {
	try {
		this->serv.undo();
	}
	catch (RepoERROR& er) {
		std::cout << er.getMessage();
	}
}

void Console::start() {
	
	/*
	try {
		addCateva();
	}
	catch (RepoERROR&) {


	}
	catch (ProbabilityERROR&) {

	}
	*/
	
	
	while (true) {
		printUi();
		int cmd;
		cin >> cmd;
		if (cin.fail()) {
			return;
		}
		switch (cmd) {
		case 1:
			try {
				adaugaUI();
			}
			catch (ValidateException&) {
				std::cout << "Nu e bine\n";
				continue;
			}
			catch (RepoERROR& ex) {
				std::cout << ex.getMessage();
				continue;
			}
			catch (ProbabilityERROR& pr) {
				std::cout << pr.getMessage();
				continue;
			}
			break;
		case 2:
			printAll(serv.getAll());
			break;
		case 3:
			try {
				modificaUi();
			}
			catch (const ModificaERROR& error) {
				cout << error.getMessage();
			}
			catch (ValidateException&) {
				cout << "Gresit\n";
			}
			break;
		case 4:
			deleteUi();
			break;
		case 5:
			cautaActivitate();
			break;
		case 6:
			filtrareDescriere();
			break;
		case 7:
			filtrareTip();
			break;
		case 9:
			printAll(serv.sortareDescriere());
			break;
		case 8:
			printAll(serv.sortareTitlu());
			break;
		case 10:
			printAll(serv.sortareTipSiDurata());
			break;
		case 11:
			raportUi();
			break;
		case 13:
			adaugaInListaUi();
			break;
		case 12:
			afiseazaLista();
			break;
		case 15:
			golesteLista();
			break;
		case 14:
			randomUi();
			break;
		case 16:
			exportCvsUi();
			break;
		case 17:
			exportHtmlUi();
		case 18:
			undoUi();
			break;
		case 0:
			return;
		default:
			cout << "Comanda invalida\n";
		}
	}
}