#include "service.h"
#include <assert.h>

void testFiltru() {
	Repo rep{ "debug.txt" };
	Service srv{ rep };
	vector<Produs>v;
	v = srv.getAll();
	assert(v.size() == 2);
	v = srv.getFiltru();
	assert(v.size() == 1);
}