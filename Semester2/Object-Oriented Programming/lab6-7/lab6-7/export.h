#pragma once
#include <string>
#include <vector>
#include "Activity.h"
/*
Scrie in fisierul fName lista de act
in format Comma Separated Values
arunca exc daca nu poate crea fisierul
*/
void exportToCVS(const std::string& fName, const std::vector<Activity>& acts);
/*
Scrie in fisierul fName lista de animale
in format HTML
arunca exc daca nu poate crea fisierul
*/
void exportToHTML(const std::string& fName, const std::vector<Activity>& acts);