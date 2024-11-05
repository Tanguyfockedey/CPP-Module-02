/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:25:50 by tafocked          #+#    #+#             */
/*   Updated: 2024/11/05 17:57:59 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a = 10.f;
	Fixed	b = 5.f;
	Fixed	c;

	c = a / b;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min((const Fixed)a, (const Fixed)b) << std::endl;
	return (0);
}
