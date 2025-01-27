//CABECERA

#define RED	"\033[1;38;5;9m"
#define RESET	"\033[0m"

#include "Base.hpp"
#include <stdlib.h>
#include <iostream>
#include <exception>
#include <string>

Base	*generate( void );
void	identify( Base &p );
void	identify( Base *p );

int	main( void )
{
	Base	*p;

	srand( time(NULL));
	for ( int i = 0; i < 10; i++)
	{
		p = generate();
		std::cout << "-----------------------" << std::endl;
		identify ( p );
		identify ( *p );
		if ( p )
		{
			delete( p );
			p = NULL;
		}
	}
	std::cout << "-----------------------" << std::endl;
	identify ( p );
	identify ( *p );
	std::cout << "-----------------------" << std::endl;
	return ( 0 );
}

Base	*generate( void )
{
	int		selection;
	
	selection = rand() % 3;
	switch ( selection )
	{
		case 0:
			return( new A());
		case 1:
			return( new B());
		case 2:
			return( new C());	
	}
	return ( NULL );
}

void	identify( Base *p )
{
	std::string	classType;
	
	if ( dynamic_cast<A *>(p) != NULL)
		classType = 'A';
	else if ( dynamic_cast<B *>(p) != NULL)
		classType = 'B';
	else if ( dynamic_cast<C *>(p) != NULL)
		classType = 'C';
	else
		classType = "NULL";
	std::cout << "identify *: " <<classType << std::endl;
}

void	identify( Base &p )
{
	std::string	classType;
	
	try
	{
		dynamic_cast<A &>(p);
		classType = 'A';
	}
	catch( std::exception &bc)
	{
		try
		{
			dynamic_cast<B &>(p);
			classType = 'B';
		}
		catch ( std::exception &bc )
		{
			try
			{
				dynamic_cast<C &>(p);
				classType = 'C';
			}
			catch (std::exception &bc )
			{
				classType = "NULL";
				std::cout << RED << "ERROR: " <<  bc.what() << RESET << std::endl;
				return ;
			}
		}
	}
	std::cout << "identify &: " << classType << std::endl;
}
