// CABECERA


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
