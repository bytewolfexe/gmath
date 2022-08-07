#ifndef GMATH_ANGLE_MATH_HPP
#define GMATH_ANGLE_MATH_HPP

#include "shared.hpp"

namespace gmath
{
	constexpr GMATH_ANGLE gPI = 3.14159265358979323846264;
	constexpr GMATH_ANGLE gDeg2Rad = gPI / 180;
	constexpr GMATH_ANGLE gRad2Deg = (GMATH_ANGLE)180 / gPI;

	inline GMATH_ANGLE toRadians(GMATH_ANGLE degrees)
	{
		return degrees * gDeg2Rad;
	}

	inline GMATH_ANGLE toDegrees(GMATH_ANGLE radians)
	{
		return radians * gRad2Deg;
	}
}

#endif //GMATH_ANGLE_MATH_HPP
