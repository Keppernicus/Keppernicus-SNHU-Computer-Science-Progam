#include "DataHandler.h"
#include <fstream>
#include <iostream>

DataHandler::DataHandler(const std::string& inputFile, const std::string& backupFile)
	: inputFileName(inputFile), backupFileName(backupFile) {
}

void DataHandler::loadData()
{
	//open file to read if possible, if not throw error

	std::ifstream inFS(inputFileName);
	if (!inFS.is_open()) {
		throw std::runtime_error("Could not open input file: " + inputFileName);
	}

	// create a variable for the iteration
	std::string currWord;

	// get a count of each item from the input file
	while (inFS >> currWord)
	{
		++freqMap[currWord];
	}

	inFS.close();
}

void DataHandler::writeToBackup() const
{
	//open file to write if possible, if not throw error
	std::ofstream outFS(backupFileName);
	if (!outFS.is_open())
	{
		std::cerr << "Error: could not open backup file "
			<< backupFileName << " to write\n";

		return; // end the program
	}
	// Chose to iterate here with auto, it's much more human-readable
	for (const auto& kv : freqMap)
	{
		outFS << kv.first << " " << kv.second << "\n";
	}
	outFS.close();
}

// Used auto in here again for readability.
int DataHandler::getFrequency(const std::string& item) const
{
	auto it = freqMap.find(item);
	// the ? 
	return (it != freqMap.end()) ? it->second : 0;
}

// get the whole freq map back
const std::map<std::string, int> DataHandler::getAllFrequencies() const
{
	return freqMap;
}
