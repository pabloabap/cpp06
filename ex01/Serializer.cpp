/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:07:26 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/28 18:07:29 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ){}

Serializer::Serializer( Serializer const &src ){ ( void )src; }

Serializer::~Serializer( void ){}

Serializer	 &Serializer::operator=( Serializer const &src){ (void)src; return ( *this ); }

uintptr_t	Serializer::serialize( Data *ptr )
{
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data*		Serializer::deserialize( uintptr_t raw )
{
	return ( reinterpret_cast<Data *>(raw) );
}
