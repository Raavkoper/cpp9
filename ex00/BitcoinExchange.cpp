#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
	: inputfile("null"), datafile("data.csv") {
	return ;
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
	std::string line;
	std::string date;
	std::string price;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, ',');
		data[date] = std::stof(price);
	}
}

int error_checks(std::string line, std::string amount) {
	try {
		if (std::stoi(amount) < 0) {
			std::cerr << "Error: negative amount." << std::endl;
			return 1;
		}
	} catch (std::exception &e) {
		std::cerr << "Error: number out of int range." << std::endl;
		return 1;
	}
	return (0);
}

void find_date(std::string &line, std::map<std::string, float> data) {
	std::map<std::string, float>::iterator it = data.lower_bound(line);
	it--;
	line = it->first;
}

void BitcoinExchange::print() {
	std::ifstream file(inputfile);
	std::string amount, line, datetoprint;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		if (line.find('|') == -1) {
			std::cerr << "Error: invalid line." << std::endl;
			continue;
		}
		std::getline(ss, line, '|');
		line = line.substr(0, 10);
		datetoprint = line;
		if (data.find(line) == data.end()) {
			find_date(line, data);
		}
		std::getline(ss, amount, '|');
		if (error_checks(line, amount))
			continue;
		std::cout << datetoprint << " =>" << amount << " = " << data[line] * std::stof(amount) << std::endl;
	}
}
