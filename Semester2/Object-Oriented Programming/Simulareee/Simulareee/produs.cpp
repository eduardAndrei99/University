#include "produs.h"
#include <assert.h>

void testProdus() {
	Produs p{ "zahar", 2, true };
	assert(p.getNume() == "zahar");
	assert(p.getCantitate() == 2);
	assert(p.getCumparat() == true);
}