/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:30:07 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/30 18:53:43 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(): _RawBits(0)
{}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int n)
{
	this->_RawBits = n << this->_frac;
}

Fixed::Fixed(const float n)
{
	this->_RawBits = roundf(n * (1 << this->_frac));
}

Fixed	&Fixed::operator =(const Fixed &copy)
{
	if (this != &copy)
		this->_RawBits = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->_RawBits < fixed.getRawBits());
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->_RawBits > fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->_RawBits <= fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->_RawBits >= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (this->_RawBits == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->_RawBits != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	Fixed	result;
	
	result.setRawBits(this->getRawBits() / (1 << this->_frac) * fixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	Fixed	result;
	
	result.setRawBits(this->getRawBits() * (1 << this->_frac) / fixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator++(void)
{
	this->_RawBits++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_RawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	this->_RawBits++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	this->_RawBits--;
	return (tmp);
}

int	Fixed::getRawBits(void) const
{
	return (this->_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_RawBits / (1 << this->_frac));
}

int	Fixed::toInt(void) const
{
	return (this->_RawBits >> this->_frac);
}

static Fixed	&min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

static const Fixed	&min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

static Fixed	&max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

static const Fixed	&max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}

