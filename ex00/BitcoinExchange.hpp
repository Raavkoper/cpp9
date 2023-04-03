#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
 
class BitcoinExchange {
private: 
	const std::string datafile;
	const std::string inputfile;
	std::map<std::string, float> data;

public: 
	BitcoinExchange(); 
	BitcoinExchange( const std::string new_inputfile );
	BitcoinExchange( const BitcoinExchange &other); 
	~BitcoinExchange(); 
	BitcoinExchange& operator=( const BitcoinExchange &other);
	void initialize();
	void print();
};

#endif
