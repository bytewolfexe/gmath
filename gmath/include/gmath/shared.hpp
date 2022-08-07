#ifndef GMATH_SHARED_HPP
#define GMATH_SHARED_HPP

#include <cmath>
#include <iostream>

#ifndef GMATH_HIGH_PRECISION
#define GMATH_ANGLE double
#define GMATH_LENGTH double
#else
#define GMATH_ANGLE float
#define GMATH_LENGTH float
#endif

#ifndef GMATH_NO_ASSERT
#define GMATH_ASSERT(condition, message)\
do\
{\
	if(!(condition))\
	{\
		std::cerr << "ASSERTION FAILED : " << message << "\n";\
		std::exit(-1);\
	}\
}while(0)
#else
#define GMATH_ASSERT(c, m)
#endif

namespace gmath
{

}

#endif //GMATH_SHARED_HPP
