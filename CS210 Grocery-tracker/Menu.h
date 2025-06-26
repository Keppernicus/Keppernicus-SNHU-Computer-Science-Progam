#ifndef MENU_H
#define MENU_H
#include "DataHandler.h"
#include <string>


// had to add this after everything was done, the input was case sensitive, not very intuitive for end users
std::string capitalizeFirstLetter(const std::string& input);

class Menu
{
public:

	// a constructor that calls to DataHandler, so we're looking at the right data
	Menu(DataHandler& handler);

	// repeat the loop until user exits
	void run();


private:
	DataHandler& dataHandler;

	// menu options
	void optionOne(); // Unique item + count
	void optionTwo(); // all items and their count
	void optionThree(); // histogram option

	// need this to display the menu with validated choice
	int getUserChoice() const;

	// repeat prompt until the user enters valid item or exits
	std::string getValidItem() const;
};


#endif
