#include "Activity.h"
#include <assert.h>
#include <iostream>

Activity::Activity(std::string nTitle, std::string nDescription,std::string nType, int nTime) 
	:title{ nTitle }, description{ nDescription },type{ nType }, time{ nTime } {
}

Activity::Activity(const Activity& ot) : title{ ot.title }, description{ ot.description },
type{ ot.type }, time{ ot.time } {
	//std::cout << "Copy\n";
}

