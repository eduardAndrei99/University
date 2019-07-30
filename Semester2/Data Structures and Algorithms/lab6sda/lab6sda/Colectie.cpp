#include "Colectie.h"
#include "IteratorColectie.h"

IteratorColectie Colectie:: iterator() const {
	return IteratorColectie(*this);
}