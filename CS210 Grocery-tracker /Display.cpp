#include "Display.h"
#include <iostream>


// print all the items with their respective count
void printFrequencies(const std::map < std::string, int>& freqMap)
{
	for (const auto& kv : freqMap)
	{
		std::cout << kv.first << " " << kv.second << "\n" << std::flush;
	}
}

// print a histogram with each item and * for each unique entry
void printHistogram(const std::map<std::string, int>& freqMap,
	char symbol)
{
	for (const auto& kv : freqMap)
	{
		std::cout << kv.first << " ";
		for (int i = 0; i < kv.second; ++i)
		{
			std::cout << symbol;
		}
		std::cout << "\n" << std::flush;
	}
}
