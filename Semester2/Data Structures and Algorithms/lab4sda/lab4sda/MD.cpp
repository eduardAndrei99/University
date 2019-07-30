#include "MD.h"
#include "IteratorMd.H"

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}