#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Fixed {
	private:
		int _nb;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed(const int a);
		Fixed(const float a);
		Fixed &operator = (const Fixed &a);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		friend ostream& operator<<(ostream& os, const Fixed &dt);
};

#endif