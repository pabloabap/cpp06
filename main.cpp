/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:31:36 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/24 16:59:44 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main( int argc, char **argv )
{
	if (argc == 2 )
	{
		ScalarConverter::convert(argv[1]);
	}
	else
	{
		std::cout << "Usage: ./conversor <char|int|float|double>\n"
			<< " - char example: \"'a'\", \"'c'\" ...\n"
			<< " - int example: 0, -42, 42 ...\n"
			<< " - float example: 0.0f, -4.2f, 4.2f ..."
			<< " Also accepted -inff, +inff and nanf\n"
			<< " - double example: 0.0, -4.2, 4.2 ..." 
			<< " Also accepted -inf, +inf and nan"
			<< std::endl;
	}
	return ( 0 );
}
