/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:23:57 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/28 17:49:02 by pabad-ap         ###   ########.fr       */
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

void 	ScalarConverter::convert( std::string str)
{
	str = ft_trim( str );
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
	if ( ScalarConverter::_pseudosHandler( str ) \
		|| ScalarConverter::_charHandler( str ) \
		|| ScalarConverter::_intHandler( str ) \
		|| ScalarConverter::_realNumHandler( str ) \
		){}
	else
		std::cout << RED << "Error: Invalid format" << RESET << std::endl;
}

/** Handle special cases, only available for float and double */
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
	else if ( "" == str  && !handled++ )
		std::cout << RED << "Error: Invalid format" << RESET << std::endl;
	return ( handled );
}

/** Manage output message of char input. */
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

/** Manage output message of int input.*/
bool	ScalarConverter::_intHandler( std::string str )
{
	int			sign;
	std::stringstream	strIntMax;
	std::stringstream	strIntMin;
		
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

/** Manage real numbers (float and double) cases*/
bool	ScalarConverter::_realNumHandler( std::string str )
{
	int	dots 	= 0;
	bool	isFloat = ( str[str.length() - 1] == 'f' );
	int	bugs	= 0;
	int	sign 	= 1;
	
	switch (str[0])
	{
		case '-':
			sign = -1;
			//fallthrough
		case '+':
			str = str.substr(1); 
			break;
	}
	for ( std::string::iterator it = str.begin(); it != str.end(); it++ )	
	{
		if (!isdigit( *it ))
		{
			if ( '.' == *it && 0 == dots )
				dots++;
			else
				bugs ++;
		}
	}
	if ( isFloat && 1 == bugs && 2 < str.length() )
		return ( ScalarConverter::_floatHandler( str , sign ));
	else if ( 1 == dots  && !bugs && 1 < str.length())
		return ( ScalarConverter::_doubleHandler( str , sign ));
	else
		return ( false );
}

/** Manage float output */
bool	ScalarConverter::_floatHandler( std::string str, double sign )
{
	int	handled = 0;
	double	num = strtod( str.c_str(), NULL ) * sign;
	
	if ( ( num < -FLT_MAX || num > FLT_MAX || errno == ERANGE ) && !handled++ )
		std::cout << RED << "Error: FLOAT overflow" << RESET << std::endl;
	else
	{
		ScalarConverter::_printChar( static_cast<int>( num ));
		ScalarConverter::_printInt( static_cast<double>( num ));
		std::cout << "float: " << static_cast<float>( num ) << "f" << "\n"
			<< "double: " << static_cast<double>( num ) << std::endl;
		handled ++;
	}
	return ( handled );
}

/** Manage double output */
bool	ScalarConverter::_doubleHandler( std::string str, double sign )
{
	int	handled = 0;
	double	num = strtod( str.c_str(), NULL ) * sign;
	
	if ( errno == ERANGE && !handled++ )
		std::cout << RED << "Error: DOUBLE overflow" << RESET << std::endl;
	else
	{
		ScalarConverter::_printChar( static_cast<int>( num ));
		ScalarConverter::_printInt( static_cast<double>( num ));
		ScalarConverter::_printFloat( static_cast<double>( num ));
		std::cout << "double: " << static_cast<double>( num ) << std::endl;
		handled ++;
	}
	return ( handled );
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
	{
		char_msg = "'";
		char_msg += static_cast<char>( n );
		char_msg += "'";
	}
	std::cout << "char: " << char_msg << std::endl;
}

/** Handle options of int printing based on 
 * the double received as input:
 * - Out of int range.
 * - In int range.
 *
 * @param [double] n: Integer to interpret.
 *
 * @return Nothing, print expected message in STDOUT.
*/
void	ScalarConverter::_printInt( double n )
{
	if ( n < static_cast<double>( INT_MIN ) \
		|| n > static_cast<double>( INT_MAX ))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>( n ) << std::endl;
}

/** Handle options of float printing based on 
 * the double received as input:
 * - Out of float range.
 * - In float range.
 *
 * @param [double] n: Integer to interpret.
 *
 * @return Nothing, print expected message in STDOUT.
*/
void	ScalarConverter::_printFloat( double n )
{
	std::string	int_msg;

	if ( n < static_cast<double>( -FLT_MAX ) \
		|| n > static_cast<double>( FLT_MAX ))
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>( n ) << "f" << std::endl;
}
