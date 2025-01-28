/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:08:48 by pabad-ap          #+#    #+#             */
/*   Updated: 2025/01/28 18:08:50 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

class Base
{
	public:
		virtual	~Base( void );	
		Base	*generate( void );
		void	identify( Base *p);
		void	identify( Base &p);
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

#endif
