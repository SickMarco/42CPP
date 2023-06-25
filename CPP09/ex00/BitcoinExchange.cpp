/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:16:48 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/25 18:45:44 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool validFile(const std::string& path) {
	std::ifstream file(path.c_str());
	if (!file)
		return false;
	return true;
}

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& database, const std::string& list){
	if (!validFile(database) || !validFile(list))
		throw std::runtime_error("Error: could not open file");
	mapper(database, list);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : dataMap(src.dataMap), listMap(src.listMap){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){
	if (this != &src){
		this->dataMap = src.dataMap;
		this->listMap = src.listMap;
	}
	return *this;
}

void BitcoinExchange::mapper(const std::string& database, const std::string& list){
	std::string line;
	std::string date;
    float value;

	std::ifstream db(database.c_str());
	while (std::getline(db, line)){
		std::istringstream ss(line);
        std::getline(ss, date, ',');
        ss >> value;
        dataMap[date] = value;
	}

	std::ifstream lst(list.c_str());
	while (std::getline(lst, line)){
		std::istringstream ss(line);
        std::getline(ss, date, ',');
        ss >> value;
        listMap[date] = value;
	}
}

void BitcoinExchange::exchanger() const {
	
}