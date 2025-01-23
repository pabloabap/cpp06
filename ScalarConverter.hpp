// CABECERA

#ifndef SCALAR_CONVERTER_CLASS_HPP
# define SCALAR_CONVERTER_CLASS_HPP

# include <string>

class ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &src);
		~ScalarConverter( void );

		ScalarConverter	&operator=( ScalarConverter const &src );
	public:

		static void	convert( std::string const &str );
}

#endif
