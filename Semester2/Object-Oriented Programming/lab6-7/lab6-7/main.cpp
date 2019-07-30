#include "Activity.h"
#include "test.h"
#include "Console.h"
#include "Service.h"
#include "validator.h"
#include "ActivityRepo.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 

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
}

int main() {
	{
		allTest();
		ActivityRepo repo{};
		ActivityValidator val;
		Service service{ repo, val };
		Console console{ service };

		console.start();
	}
	_CrtDumpMemoryLeaks();

	return 0;
}