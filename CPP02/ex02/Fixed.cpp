/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:06 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/24 16:59:25 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

// CONSTRUCTOR
Fixed::Fixed() : _fixedNb(0) {
	std::cout << "Default constructor called" << std::endl;
}

// INT CONSTRUCTOR
Fixed::Fixed(const int initNb) : _fixedNb(initNb << _fractBits){
	std::cout << "Int constructor called" << std::endl;
}

// FLOAT CONSTRUCTOR
Fixed::Fixed(const float initNb) : _fixedNb(roundf(initNb * (1 << _fractBits))) {
	std::cout << "Float constructor called" << std::endl;
}

// COPY CONTRUCTOR
Fixed::Fixed(const Fixed& oldClass) {
	std::cout << "Copy constructor called" << std::endl;
	*this = oldClass;
}

// DESTRUCTOR
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// COPY ASSIGNMENT OPERATOR (= OVERLOAD)
Fixed& Fixed::operator = (const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fixedNb = src._fixedNb;
	return *this;
}

// << OVERLOAD
std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}

// + OVERLOAD
Fixed Fixed::operator+(const Fixed& add) const {
	return Fixed(toFloat() + add.toFloat());
}

// - OVERLOAD
Fixed Fixed::operator-( const Fixed& sub) const {
	return Fixed(toFloat() - sub.toFloat());
}

// * OVERLOAD
Fixed Fixed::operator*( const Fixed& mult ) const {
	return Fixed(toFloat() * mult.toFloat());
}

Fixed Fixed::operator/( const Fixed& mult ) const {
	return Fixed(toFloat() / mult.toFloat());
}

// ++ OVERLOAD
Fixed& Fixed::operator++(void){
	++_fixedNb;
	return *this;
}

// OVERLOAD ++
Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	++_fixedNb;
	return tmp;
}

// -- OVERLOAD
Fixed& Fixed::operator--(void){
	--_fixedNb;
	return *this;
}

// OVERLOAD --
Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	--_fixedNb;
	return tmp;
}

// COMPARISON
bool Fixed::operator>(const Fixed& cmp) const {
	return (this->_fixedNb > cmp._fixedNb);
}

bool Fixed::operator>=(const Fixed& cmp) const {
	return (this->_fixedNb >= cmp._fixedNb);
}

bool Fixed::operator<(const Fixed& cmp) const {
	return (this->_fixedNb < cmp._fixedNb);
}

bool Fixed::operator<=(const Fixed& cmp) const {
	return (this->_fixedNb <= cmp._fixedNb);
}

bool Fixed::operator==(const Fixed& cmp) const {
	return (this->_fixedNb == cmp._fixedNb);
}

bool Fixed::operator!=(const Fixed& cmp) const {
	return (this->_fixedNb != cmp._fixedNb);
}

// MEMBER FUNCTIONS
int Fixed::getRawBits(void) const{
	return _fixedNb;
}

void Fixed::setRawBits(int const raw){
	_fixedNb = raw;
}

float Fixed::toFloat(void) const{
	return (float)_fixedNb / (1 << _fractBits); 
}

int Fixed::toInt(void) const{
	return _fixedNb >> _fractBits;
}

Fixed& Fixed::min(Fixed& x, Fixed& y){
	return (x < y ? x : y);
}

const Fixed& Fixed::min(const Fixed& x, const Fixed& y){
	return (x < y ? x : y);
}

Fixed& Fixed::max(Fixed& x, Fixed& y){
	return (x > y ? x : y);
}

const Fixed& Fixed::max(const Fixed& x, const Fixed& y){
	return (x > y ? x : y);
}