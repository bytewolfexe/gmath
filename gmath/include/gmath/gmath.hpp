#ifndef GMATH_GMATH_HPP
#define GMATH_GMATH_HPP

#include "shared.hpp"
#include "angle_math.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

#include "matrix4.h"

namespace gmath
{
	using vec2f = vector2<float>;
	using vec2d = vector2<double>;

	using vec3f = vector3<float>;
	using vec3d = vector3<double>;

	using vec4f = vector4<float>;
	using vec4d = vector4<double>;

	using mat4f = matrix4<float>;
	using mat4d = matrix4<double>;
}

#endif //GMATH_GMATH_HPP
