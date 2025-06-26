#pragma once
#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <map>
#include <string>


class DataHandler
{
public:
	// The constructor for the class, with filenames provided
	DataHandler(const std::string& inputFile = "CS210_Project_Three_Input_File.txt",
		const std::string& backupFile = "frequency.dat");

	//Load the data from the inputFile into the map
	void loadData();

	// get the count/frequency of the item
	int getFrequency(const std::string& item) const;

	// get the completed map with items & their count
	const std::map<std::string, int> getAllFrequencies() const;

	// write the new map to a backup file
	void writeToBackup() const;

private:
	std::string inputFileName; // filepath to the input file
	std::string backupFileName; // filepath for the output file
	std::map<std::string, int> freqMap; // Map of the items & their count

};
#endif 
