/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:16:48 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/30 15:57:03 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

bool isValidFile(const std::string& path) {
	std::ifstream file(path.c_str());
	if (!file)
		return false;
	file.close();
	return true;
}

BitcoinExchange::BitcoinExchange(const std::string& database, const std::string& list){
	if (!isValidFile(database) || !isValidFile(list))
		throw std::runtime_error("Error: could not open file");
	this->listPath = list;
	mapper(database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : dataMap(src.dataMap), listPath(src.listPath){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){
	if (this != &src){
		this->dataMap = src.dataMap;
		this->listPath = src.listPath;
	}
	return *this;
}

void BitcoinExchange::mapper(const std::string& database){
	std::string line, date;
	std::ifstream db(database.c_str());
	float value;
	while (std::getline(db, line)){
		std::istringstream iss(line);
        std::getline(iss, date, ',');
        iss >> value;
        dataMap[date] = value;
	}
	db.close();
}

bool dateFinder(const std::string& date1, const std::string& date2){
	return date1.compare(date2) <= 0;
}

bool isDateValid(const std::string& date){
    std::istringstream iss(date);
    int year, month, day;
    char delimiter;

    if (iss >> year >> delimiter >> month >> delimiter >> day)
            if (year >= 2009 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
                return true;
    return false;
}

void printer(const std::string& targetDate, const float& dataValue, const float& listValue){
	if (!isDateValid(targetDate))
		std::cerr << "Error: bad input => " << targetDate << std::endl;
	else if (listValue < 0)
		std::cerr << "Error: not a positive number." << std::endl;
	else if (listValue > 1000)
		std::cerr << "Error: too large number." << std::endl;
	else
		std::cout << targetDate << " => " << listValue << " = " << std::fixed << std::setprecision(2) << listValue * dataValue << std::endl;
}

void BitcoinExchange::exchanger() const {
	std::string line, targetDate;
	float dataValue, listValue;

	std::ifstream lst(listPath.c_str());
	std::getline(lst, line);
	while (std::getline(lst, line))
	{
		std::istringstream iss(line);
		std::getline(iss, targetDate, '|');
		iss >> listValue;
		for (std::map<std::string, float>::const_reverse_iterator rit = dataMap.rbegin(); rit != dataMap.rend(); ++rit){
			if (dateFinder(rit->first, targetDate)){
				dataValue = rit->second;
				break;
			}
		}
		printer(targetDate, dataValue, listValue);
	}
	lst.close();
}