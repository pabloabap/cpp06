//CABECERA

#include "Serializer.hpp"
#include <iostream>


int	main( void )
{
	Data		a;
	uintptr_t	uiPtr;
	Data		*newPtr;

	a.n = 999;
	a.serialized = Serializer::serialize( &a );
	uiPtr = Serializer::serialize( &a );
	newPtr = Serializer::deserialize( uiPtr );
	std::cout << "UIPTR: " << uiPtr
		<< "\nSERIALIZED: " << a.serialized
		<< "\nDATA *: " << &a
		<< "\nDESSERIALIZED: " << newPtr
		<< "\nEQUAL SERIAL: " << (uiPtr == a.serialized)
		<< "\nEQUAL DESSERIAL: " << ( &a == newPtr ) << std::endl;
	

	return ( 0 );
}
