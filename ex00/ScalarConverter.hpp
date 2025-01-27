/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:23:51 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/24 20:11:23 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_CLASS_HPP
# define SCALAR_CONVERTER_CLASS_HPP

# define RED "\033[1;38;5;9m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <climits>
# include <cfloat>
# include <limits>
# include <sstream>
# include <cctype>
# include <cstdlib>
# include <cerrno>

# include "ft_utils.hpp"

class ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &src);
		~ScalarConverter( void );

		ScalarConverter	&operator=( ScalarConverter const &src );

		static bool	_pseudosHandler( std::string str );
		static bool	_charHandler( std::string str );
		static bool	_intHandler( std::string str );
		static bool	_realNumHandler( std::string str );
		static bool	_floatHandler( std::string str, double sign );
		static bool	_doubleHandler( std::string str, double sign );

		static void	_printChar( int n );
		static void	_printInt( double n );
		static void	_printFloat( double n );
	public:

		static void	convert( std::string str );
};

#endif
