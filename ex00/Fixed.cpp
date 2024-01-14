#include "Fixed.hpp"

Fixed::Fixed()
{
        std::cout << "Default constructor called" << std::endl;
        this->m_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
        std::cout << "Copy constructor called" << std::endl;
        this->setRawBits(copy.getRawBits());
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
        std::cout << "getRawBits member function called" << std::endl;
        return this->m_value;
}

void    Fixed::setRawBits(int const raw)
{
       this->m_value = raw;
}
