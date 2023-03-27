#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
 
class BitcoinExchange {
private: 
	const std::string datafile;
	const std::string inputfile;
	std::vector<std::string> date;
	std::vector<float> price;

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
