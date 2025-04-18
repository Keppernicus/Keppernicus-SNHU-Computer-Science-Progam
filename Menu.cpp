
#include "Menu.h"
#include "Display.h"
#include <iostream>
#include <limits>
#include <stdexcept>

// constructor for the DataHandler reference
Menu::Menu(DataHandler& handler) : dataHandler(handler) {}

void Menu::run()
{
	int choice = -1;
	do
	{
		// menu options display output
		std::cout << "\n--- Corner Grocer Menu ---\n"
			<< "1. Lookup item frequency\n"
			<< "2. List all item frequencies\n"
			<< "3. Display histogram\n"
			<< "4. Exit\n"
			<< "Enter choice: ";
		// switch cases for the option choices and validation
		try
		{
			choice = getUserChoice();
			switch (choice)
			{
			case 1:
				optionOne();
				break;
			case 2:
				optionTwo();
				break;
			case 3:
				optionThree();
				break;
			case 4:
				std::cout << "Exiting...\n" << std::flush;
				break;
			default:
				throw std::out_of_range("Invalid option. Please try again.");
			}

		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			choice = -1; // This puts them back into the menu rather than closing
		}
	} while (choice != 4);
}

// get user choice, read an int or throw if it's invalid
int Menu::getUserChoice() const
{
	int input;
	if (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore();
		throw std::invalid_argument("Invalid input. Please enter a number.");
	}
	return input;
}

// whip up a title-case maker for the input since the first letter of
// each item is upper case in the input file
std::string capitalizeFirstLetter(const std::string& input) {
	if (input.empty()) return input;
	std::string result = input;
	result[0] = std::toupper(result[0]);
	for (size_t i = 1; i < result.size(); ++i)
		result[i] = std::tolower(result[i]);
	return result;
}
// validate the items, prompt the user until they enter a known item or throw error if bad entry
std::string Menu::getValidItem() const {
	while (true) {
		std::cout << "Enter item name to look up: ";
		std::string item;
		if (!(std::cin >> item)) {
			std::cin.clear();
			std::cin.ignore();
			std::cerr << "Invalid input. Please try again.\n" << std::flush;
			continue;
		}
		item = capitalizeFirstLetter(item);
		if (dataHandler.getFrequency(item) > 0) {
			return item; // get it back if it's a valid entry
		}
		std::cerr << "Item '" << item << "' not found. Please try again.\n" << std::flush;
	}
}

// the option one prompt for an item and it's count
void Menu::optionOne()
{
	std::string item = getValidItem();
	int count = dataHandler.getFrequency(item);
	std::cout << item << " appears " << count << " time(s).\n";
}

// the option two output for all the items and their count
void Menu::optionTwo()
{
	auto allFreq = dataHandler.getAllFrequencies();
	printFrequencies(allFreq);
}

// the option three output for a histogram of all items using * as the symbol
void Menu::optionThree()
{
	auto allFreq = dataHandler.getAllFrequencies();
	printHistogram(allFreq);
}