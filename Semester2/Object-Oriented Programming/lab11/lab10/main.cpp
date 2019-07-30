#include "Activity.h"
#include "test.h"
#include "Console.h"
#include "Service.h"
#include "validator.h"
#include "ActivityRepo.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#include "repoExceptii.h"
#include "UiGUI.h"
#include <qapplication.h>

void allTest() {
	testGet();
	testAdd();
	testValidare();
	testModificare();
	testStergere();
	testCauta();
	testFiltrare();
	testSort();
	testMap();
	testLista();
	testExport();
	testFisiere();
	testUndo();
	testRepoError();
}

int main(int argc, char *argv[]) {
	{
		allTest();
		QApplication a(argc, argv);
		//ProbabilityRepo repo{ 0.5 };
		ActivityRepoFile repo{"activitati.txt"};
		ActivityValidator val;
		Service service{ repo, val };
		ConsoleGui console{ service };
		console.setWindowTitle("Activity app");
		console.show();
		//console.start();
		a.exec();
	}

	return 0;
}