#include "export.h"
#include "Activity.h"
#include <fstream>
#include <string>
#include <vector>
/*
Scrie in fisierul fName lista de animale
in format Comma Separated Values
*/
void exportToCVS(const std::string& fName, const std::vector<Activity>& acts) {
	std::ofstream out(fName, std::ios::trunc);
	for (const auto& p : acts) {
		out << p.getTitle() << ",";
		out << p.getType() << ",";
		out << p.getDescription() << ",";
		out << p.getTime() << std::endl;
	}
	out.close();
}

/*
Scrie in fisierul fName lista de act
in format HTML
*/
void exportToHTML(const std::string& fName, const std::vector<Activity>& acts) {
	std::ofstream out(fName, std::ios::trunc);
	out << "<html><body>" << std::endl;
	out << "<table border=\"1\" style=\"width:100 % \">" << std::endl;
	for (const auto& p : acts) {
		out << "<tr>" << std::endl;
		out << "<td>" << p.getTitle() << "</td>" << std::endl;
		out << "<td>" << p.getType() << "</td>" << std::endl;
		out << "<td>" << p.getDescription() << "</td>" << std::endl;
		out << "<td>" << p.getTime() << "</td" << std::endl;
		out << "</tr>" << std::endl;
	}
	out << "</table>" << std::endl;
	out << "</body></html>" << std::endl;
	out.close();
}