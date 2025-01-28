/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:07:32 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/28 18:07:35 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

# include <stdint.h>

typedef struct	s_data
{
	uintptr_t	serialized;
	int		n;
}	Data;


class Serializer
{
	private:
		Serializer ( void );
		Serializer ( Serializer const &src);
		~Serializer ( void );

		Serializer	&operator=( Serializer const &src );
	public:
		static uintptr_t	serialize( Data *ptr );
		static Data*		deserialize( uintptr_t raw );	
};

#endif
