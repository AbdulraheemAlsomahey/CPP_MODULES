#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <iomanip>

class BitcoinExchange
{
    private:
    std::map<std::string, float> _rates;

    void	parseDates(std::string line);
    void	getDateAndPrint(std::string date, float val);

    bool	readDataFile();
    bool	calculate(std::string infile);
    bool	isValidDate(std::string	date);
    bool	isValidDelim(std::string	line);
    bool	isValidDMY(std::string year, std::string month, std::string day);
    float	isValidValue(std::string	val);

    public:
        BitcoinExchange();
        BitcoinExchange(std::string	infile);
        BitcoinExchange(const BitcoinExchange &object);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();
};

#endif