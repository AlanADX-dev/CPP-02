#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <math.h>

class Fixed {

        private:

                int m_value;
                static const int m_fractional_bits = 8;

        public:

                Fixed();
                Fixed(const int n);
                Fixed(const float n);
                Fixed(const Fixed &copy);
                Fixed & operator=(const Fixed &copy);

                bool    operator>(const Fixed &copy)  const;
                bool    operator<(const Fixed &copy)  const;
                bool    operator>=(const Fixed &copy) const;
                bool    operator<=(const Fixed &copy) const;
                bool    operator==(const Fixed &copy) const;
                bool    operator!=(const Fixed &copy) const;

                Fixed   operator+(const Fixed &copy) const;
                Fixed   operator-(const Fixed &copy) const;
                Fixed   operator*(const Fixed &copy) const;
                Fixed   operator/(const Fixed &copy) const;

                Fixed & operator++(void);
                Fixed & operator--(void);

                Fixed operator++(int);
                Fixed operator--(int);


                ~Fixed();

                static  Fixed& min(Fixed &a, Fixed &b);
                static  Fixed& max(Fixed &a, Fixed &b);
                static  const Fixed& min(const Fixed &a, const Fixed &b);
                static  const Fixed& max(const Fixed &a, const Fixed &b);

                int     getRawBits(void) const;
                void    setRawBits(int const raw);
                float   toFloat(void) const;
                int     toInt(void) const;

};

std::ostream & operator<<(std::ostream &o, Fixed const &i);

#endif
