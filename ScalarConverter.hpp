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

# include <iostream>
# include <string>

typedef enum e_inputType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} t_inputType;

class ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &src);
		~ScalarConverter( void );

		ScalarConverter	&operator=( ScalarConverter const &src );

		static bool	_pseudosHandler( std::string const &str );
		static bool	_charHandler( std::string const &str );
		static bool	_intHandler( std::string const &str );
	public:

		static void	convert( std::string const &str );
};

#endif
