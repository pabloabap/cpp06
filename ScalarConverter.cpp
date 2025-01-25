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

#include <limits>
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
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
	if ( ScalarConverter::_pseudosHandler( str ) \
		|| ScalarConverter::_charHandler( str ) \
		|| ScalarConverter::_intHandler( str ) ){};
}

bool	ScalarConverter::_pseudosHandler( std::string str )
{
	int	handled;
		
	handled = 0;
	if ( ("-inf" == str || "+inf" == str || "nan" == str ) && !handled++)
	{
		std::cout << "char: impossible" << "\n"
			<< "int: impossible" << "\n"
			<< "float: " << str << "f" << "\n"
			<< "double: " << str << std::endl;
	}
	else if ( ("-inff" == str || "+inff" == str || "nanf" == str) && !handled++ )
	{
		std::cout << "char: impossible" << "\n"		
			<< "int: impossible" << "\n"
			<< "float: " << str << "\n"
			<< "double: " << str.substr( 0, str.length() - 1 ) << std::endl;
	}
	return ( handled );
}

bool	ScalarConverter::_charHandler( std::string str )
{
	int	handled;
		
	handled = 0;
	
	if ( (3 == str.length() && '\'' == str[0] && '\'' == str[2] ) && !handled++ )
	{
		std::cout << "char: '" << static_cast<char>(str[1]) << "'\n"
			<< "int: " << static_cast<int>(str[1]) << "\n"
			<< "float: " << static_cast<float>(str[1]) << "f" << "\n"
			<< "double: " << static_cast<double>(str[1]) << std::endl;
	}
	return ( handled );
}

bool	ScalarConverter::_intHandler( std::string str )
{
	int			issues;
	int			sign;
	std::stringstream	strIntMax;
	std::stringstream	strIntMin;
		
	issues = 0;
	sign = 1;
	strIntMax << INT_MAX;
	strIntMin << INT_MIN;
	switch (str[0])
	{
		case '-':
			sign = -1;
			//fallthrough
		case '+':
			str = str.substr(1); 
			break;
	}
	while (str[0] == '0')
		str = str.substr(1);
	for ( std::string::iterator it = str.begin(); it != str.end(); it++ )
	{
		if ( !isdigit( *it ) )
			return ( false );	
	}	
	if ( str.length() >= strIntMax.str().length() \
		&& ( ( 1 == sign && 0 < str.compare(strIntMax.str()) ) \
			|| ( -1 == sign && 0 < str.compare(strIntMin.str().substr(1) ))))
	{
		std::cout << RED << "Error: INT overflow" << RESET << std::endl;
	}
	else
	{
		ScalarConverter::_printChar( atoi( str.c_str()) * sign );
		std::cout << "int: " << static_cast<int>(atoi(str.c_str()) * sign ) << "\n"
			<< "float: " << static_cast<float>(atoi(str.c_str()) * sign ) << "f" << "\n"
			<< "double: " << static_cast<double>(atoi(str.c_str()) * sign ) << std::endl;
	}
	return ( true );
}

/** Handle options of char printing based on 
 * the number received as input ( int, double or float ) casted to int:
 * - Out of ascii range.
 * - Non printable characters.
 * - Printable character.
 *
 * @param [int] n: Integer to interpret.
 *
 * @return Nothing, print expected message in STDOUT.
*/
void	ScalarConverter::_printChar( int n )
{
	std::string	char_msg;

	if ( !isascii( n ) )
		char_msg = "Impossible";
	else if ( !isprint( n ) )
		char_msg = "Non displayable";
	else
		char_msg = static_cast<char>( n );
	std::cout << "char: " << char_msg << std::endl;
}

