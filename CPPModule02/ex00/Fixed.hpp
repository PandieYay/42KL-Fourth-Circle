#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;

class Fixed {
	private:
		int _nb;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed &operator = (const Fixed &a);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif