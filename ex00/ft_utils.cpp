/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:38:06 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/28 17:40:13 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.hpp"

static	std::string	ft_ltrim( std::string str );
static	std::string	ft_rtrim( std::string str );

std::string		ft_trim( std::string str )
{
	str = ft_ltrim( str );
	return ( ft_rtrim( str ) );
}

// Remove leading isspace characters in a string
static	std::string	ft_ltrim( std::string str )
{
	size_t	i = 0;
	
	for ( std::string::iterator it = str.begin(); it != str.end(); it++ )
	{
		if ( !(isspace( *it )))
			break;
		i ++;
	}
	str = str.substr( i, str.length() );
	return ( str );
}

// Remove trailing isspace characters in a string
static	std::string	ft_rtrim( std::string str )
{
	size_t	i = 0;
	
	for ( std::string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it )
	{
		if ( !(isspace( *it )))
			break;
		i ++;
	}
	str = str.substr( 0, str.length() - i);
	return ( str );
	
}
