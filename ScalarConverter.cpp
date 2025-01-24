/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:23:57 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/24 20:26:33 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter( void ){}

ScalarConverter::ScalarConverter( ScalarConverter const &src)
{
	( void ) src;
}

ScalarConverter::~ScalarConverter( void ){}

ScalarConverter	&ScalarConverter::operator=( ScalarConverter const &src )
{
	( void )src;
	return ( *this );
}

void 	ScalarConverter::convert( std::string const &str)
{
	if ( ScalarConverter::_pseudosHandler( str ) \
		|| ScalarConverter::_charHandler( str ) ){};
}

bool	ScalarConverter::_pseudosHandler( std::string const &str )
{
	bool	handled;
		
	handled = false;
	if ( "-inf" == str || "+inf" == str || "nan" == str \
		|| "-inff" == str || "+inff" == str || "nanf" == str )
	{

		std::cout << "char: impossible" << "\n"
			<< "int: impossible" << "\n"
			<< "float: " << (float)( -0.1/0.0) << "f" << "\n"
			<< "double: " << (double)(0.0/0.0) << std::endl;
		handled = true;
	}
	return ( handled );
}

bool	ScalarConverter::_charHandler( std::string const &str )
{
	bool	handled;
		
	handled = false;
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
	
	if ( 3 == str.length() && '\'' == str[0] && '\'' == str[2] )
	{
		std::cout << "char: '" << static_cast<char>(str[1]) << "'\n"
			<< "int: " << static_cast<int>(str[1]) << "\n"
			<< "float: " << static_cast<float>(str[1]) << "f" << "\n"
			<< "double: " << static_cast<double>(str[1]) << std::endl;
		handled = true;
	}
	return ( handled );
}
