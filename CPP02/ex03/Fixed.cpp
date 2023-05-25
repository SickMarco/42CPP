/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:06 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/25 16:39:18 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

// CONSTRUCTOR
Fixed::Fixed() : _fixedNb(0) {
}

// INT CONSTRUCTOR
Fixed::Fixed(const int initNb) : _fixedNb(initNb << _fractBits){
}

// FLOAT CONSTRUCTOR
Fixed::Fixed(const float initNb) : _fixedNb(roundf(initNb * (1 << _fractBits))) {
}

// COPY CONTRUCTOR
Fixed::Fixed(const Fixed& oldClass) {
	*this = oldClass;
}

// DESTRUCTOR
Fixed::~Fixed(){
}

// COPY ASSIGNMENT OPERATOR (= OVERLOAD)
Fixed& Fixed::operator = (const Fixed& src){
	if (this != &src)
		this->setRawBits(src.getRawBits());
	return *this;
}

// << OVERLOAD
std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}

// + OVERLOAD
Fixed Fixed::operator+(const Fixed& add) const {
	return Fixed(this->toFloat() + add.toFloat());
}

// - OVERLOAD
Fixed Fixed::operator-( const Fixed& sub) const {
	return Fixed(this->toFloat() - sub.toFloat());
}

// * OVERLOAD
Fixed Fixed::operator*( const Fixed& mult ) const {
	return Fixed(this->toFloat() * mult.toFloat());
}

Fixed Fixed::operator/( const Fixed& div ) const {
	return Fixed(this->toFloat() / div.toFloat());
}

// ++ OVERLOAD
Fixed& Fixed::operator++(void){
	++this->_fixedNb;
	return *this;
}

// OVERLOAD ++
Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	++this->_fixedNb;
	return tmp;
}

// -- OVERLOAD
Fixed& Fixed::operator--(void){
	--this->_fixedNb;
	return *this;
}

// OVERLOAD --
Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	--this->_fixedNb;
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