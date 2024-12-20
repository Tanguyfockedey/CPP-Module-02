/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:30:07 by tafocked          #+#    #+#             */
/*   Updated: 2024/10/30 15:51:57 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(): _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n)
{
	std::cout << "Fixed int constructor called" << std::endl;
	this->_RawBits = n << this->_frac;
}

Fixed::Fixed(const float n)
{
	std::cout << "Fixed float constructor called" << std::endl;
	this->_RawBits = roundf(n * (1 << this->_frac));
}

Fixed	&Fixed::operator =(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_RawBits = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits() called" << std::endl;
	return (this->_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits() called" << std::endl;
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

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	return (os << fixed.toFloat());
}
