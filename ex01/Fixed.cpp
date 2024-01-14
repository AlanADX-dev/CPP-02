#include "Fixed.hpp"

Fixed::Fixed()
{
        std::cout << "Default constructor called" << std::endl;
        this->m_value = 0;
}

Fixed::Fixed(const int n)
{
        std::cout << "Int constructor called" << std::endl;
        this->m_value = n << m_fractional_bits;
}

Fixed::Fixed(const float n)
{
        std::cout << "Float constructor called" << std::endl;
        this->m_value = std::roundf(n *(1 << m_fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
        std::cout << "Copy constructor called" << std::endl;
        *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &copy)
                this->m_value = copy.getRawBits();
        return *this;
}

Fixed::~Fixed()
{
        std::cout << "Destructor called" << std::endl;

}

int    Fixed::getRawBits(void) const
{
        // std::cout << "getRawBits member function called" << std::endl;
        return this->m_value;
}

void    Fixed::setRawBits(int const raw)
{
       this->m_value = raw;
}

float   Fixed::toFloat(void) const
{
        return static_cast<float>(this->getRawBits()) / (1 << m_fractional_bits);
}

int     Fixed::toInt(void) const
{
        return this->m_value >> m_fractional_bits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}