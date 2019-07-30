#pragma once
#include <string>
class Activity {
private:
	// titlu, descriere, tip, durata
	std::string title;
	std::string description;
	std::string type;
	int time;

public:

	Activity() :title{ "" }, description{ "" }, type{ "" }, time{ -1 } {};

	/*
	 * Constructor
	 */
	Activity(std::string title,  std::string description, std::string type, int time);

	/*
	 * Return title
	 */
	std::string getTitle() const {
		return this->title;
	}

	/*
	 * Return description
	 */
	std::string getDescription() const {
		return this->description;
	}

	/*
	 * Return type
	 */
	std::string getType() const {
		return this->type;
	}

	/*
	 * Return time
	 */
	int getTime() const noexcept{
		return this->time;
	}

	/*
	 * copy constructor
	 */
	Activity(const Activity& ot);
};




