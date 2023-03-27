#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
	: inputfile("null"), datafile("data.csv") {
	this->initialize();
}

BitcoinExchange::BitcoinExchange( const std::string new_inputfile ) 
	: inputfile(new_inputfile), datafile("data.csv") {
	this->initialize();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other) {
	*this = other;
}
 
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other ) {
	return *this;
}

void BitcoinExchange::initialize() {
	std::ifstream file(datafile);

	if (!file.is_open()) {
		std::cerr << "Error opening file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, price;

		std::getline(ss, date, ',');
		std::getline(ss, price, ',');

		this->date.push_back(date);
		this->price.push_back(std::stof(price));
	}

	file.close();
}

void BitcoinExchange::print() {
	std::ifstream file(inputfile);
	std::string line;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, line, '|');
	}
}