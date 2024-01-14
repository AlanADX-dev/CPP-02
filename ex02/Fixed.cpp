#include "Fixed.hpp"

Fixed::Fixed()
{
        this->m_value = 0;
}

Fixed::Fixed(const int n)
{
        this->m_value = n << m_fractional_bits;
}

Fixed::Fixed(const float n)
{
        this->m_value = std::roundf(n *(1 << m_fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
        *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
        if (this != &copy)
                this->m_value = copy.getRawBits();
        return *this;
}

bool    Fixed::operator>(const Fixed& copy) const
{
        if (this->m_value > copy.getRawBits())
                return (true);
        return (false);
}

bool    Fixed::operator<(const Fixed& copy) const
{
        if (this->m_value < copy.getRawBits())
                return (true);
        return (false);
}

bool    Fixed::operator>=(const Fixed& copy) const
{
        if (this->m_value >= copy.getRawBits())
                return (true);
        return (false);
}

bool    Fixed::operator<=(const Fixed& copy) const
{
        if (this->m_value <= copy.getRawBits())
                return (true);
        return (false);
}

bool    Fixed::operator==(const Fixed& copy) const
{
        if (this->m_value == copy.getRawBits())
                return (true);
        return (false);
}

bool    Fixed::operator!=(const Fixed& copy) const
{
        if (this->m_value != copy.getRawBits())
                return (true);
        return (false);
}

Fixed Fixed::operator+(const Fixed& copy) const
{
        Fixed result;
        long long temp = static_cast<long long>(this->m_value) + copy.getRawBits();
        result.setRawBits(temp / (1 << m_fractional_bits));
        return result;
}

Fixed Fixed::operator-(const Fixed& copy) const
{
        Fixed result;
        long long temp = static_cast<long long>(this->m_value) - copy.getRawBits();
        result.setRawBits(temp / (1 << m_fractional_bits));
        return result;
}

Fixed Fixed::operator*(const Fixed& copy) const
{
        Fixed result;
        long long temp = static_cast<long long>(this->m_value) * copy.getRawBits();
        result.setRawBits(temp / (1 << m_fractional_bits));
        return result;
}

Fixed Fixed::operator/(const Fixed& copy) const
{
        Fixed result;
        long long temp = static_cast<long long>(this->m_value) / copy.getRawBits();
        result.setRawBits(temp / (1 << m_fractional_bits));
        return result;
}

Fixed & Fixed:: operator++(void)
{
	this->m_value += 1;
	return (*this);
}

Fixed & Fixed:: operator--(void)
{
	this->m_value -= 1;
	return (*this);
}

Fixed Fixed:: operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}


Fixed Fixed:: operator--(int)
{
	Fixed temp(*this);
	this->m_value -= 1;
	return (temp);
}

Fixed::~Fixed()
{
        // std::cout << "Destructor called" << std::endl;

}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

int    Fixed::getRawBits(void) const
{
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
