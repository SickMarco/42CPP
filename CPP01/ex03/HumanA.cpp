/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:03:32 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/21 20:03:33 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string set_name, Weapon &set_w) : name(set_name), M4(set_w) {}
HumanA::~HumanA() {}
void HumanA::attack() { std::cout << name << " attacks with their " << M4.getType() << std::endl; }