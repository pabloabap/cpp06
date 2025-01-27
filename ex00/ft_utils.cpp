// CABECERA

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
	int	i = 0;
	
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
	int	i = 0;
	
	for ( std::string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it )
	{
		if ( !(isspace( *it )))
			break;
		i ++;
	}
	str = str.substr( 0, str.length() - i);
	return ( str );
	
}
