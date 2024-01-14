#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

        private:

                int m_value;
                static const int m_fractional_bits = 8;

        public:

                Fixed();
                Fixed(const Fixed &copy);

                Fixed & operator=(const Fixed &copy);
                ~Fixed();

                int getRawBits(void) const;
                void setRawBits(int const raw);
};

#endif