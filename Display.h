#ifndef DISPLAY_H
#define DISPLAY_H
#include <map>
#include <string>

// print all the items with their respective count
void printFrequencies(const std::map < std::string, int>& freqMap);

// print a histogram with each item and * for each unique entry
void printHistogram(const std::map<std::string, int>& freqMap,
	char symbol = '*');


#endif