#include <iostream>
#include <string>
#include "DataHandler.h"
#include "Menu.h"

using namespace std;




int main() {
	// fire up DataHandler with the default filenames
	try {
		DataHandler dh;

		// load the item frequencies from the input
		dh.loadData();

		// save them to backup
		dh.writeToBackup();

		// fire up the menu
		Menu menu(dh);
		menu.run();
	}
	// had trouble with the file import, added this after
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
