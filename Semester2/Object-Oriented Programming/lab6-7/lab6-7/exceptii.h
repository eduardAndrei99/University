#pragma once
#include <string>

class ModificaERROR {
public:
	ModificaERROR()  :
		message("Modificarea nu s a facut\n") {
	}
	const std::string& getMessage() const noexcept{
		return message;
	}
private:
	std::string message;
};

class StergereERROR {
public:
	StergereERROR()  :
		message("Stergerea nu s a facut\n") {
	}
	const std::string& getMessage() const noexcept{
		return message;
	}
private:
	std::string message;
};


class CautaERROR {
public:
	CautaERROR() noexcept :
		message("Nu s a gasit \n") {
	}
	const std::string& getMessage() const noexcept{
		return message;
	}
private:
	std::string message;
};



