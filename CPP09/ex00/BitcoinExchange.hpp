/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:16:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/25 18:43:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange
{
private:
	BitcoinExchange();
	std::map<std::string, float> dataMap;
	std::map<std::string, float> listMap;
	
public:
	BitcoinExchange(const std::string& database, const std::string& list);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);
	~BitcoinExchange();

	void mapper(const std::string& database, const std::string& list);
	void exchanger() const;
};




#endif