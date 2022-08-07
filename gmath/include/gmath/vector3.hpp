#ifndef GMATH_VECTOR3_HPP
#define GMATH_VECTOR3_HPP

#include "shared.hpp"
#include "vector2.hpp"

namespace gmath
{
	template <typename Type>
	struct vector3
	{
		Type x, y, z;

		vector3()
			: x((Type)0), y((Type)0), z((Type)0)
		{}

		vector3(Type fill)
			: x(fill), y(fill), z(fill)
		{}

		vector3(Type x, const vector2<Type>& yz)
			: x(x), y(yz.x), z(yz.y)
		{}

		vector3(const vector2<Type>& xy, Type z)
			: x(xy.x), y(xy.y), z(z)
		{}

		vector3(Type x, Type y, Type z)
			: x(x), y(y), z(z)
		{}

		inline vector3<Type> operator + (const vector3<Type>& other) const
		{
			return vector3<Type>(x + other.x, y + other.y, z + other.z);
		}

		inline vector3<Type> operator - (const vector3<Type>& other) const
		{
			return vector3<Type>(x - other.x, y - other.y, z - other.z);
		}

		inline vector3<Type> operator * (const vector3<Type>& other) const
		{
			return vector3<Type>(x * other.x, y * other.y, z * other.z);
		}

		inline vector3<Type> operator / (const vector3<Type>& other) const
		{
			return vector3<Type>(x / other.x, y / other.y, z / other.z);
		}

		inline vector3<Type>& operator += (const vector3<Type>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		inline vector3<Type>& operator -= (const vector3<Type>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		inline vector3<Type>& operator *= (const vector3<Type>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		inline vector3<Type>& operator /= (const vector3<Type>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		inline bool operator == (const vector3<Type>& other) const
		{
			return (x == other.x && y == other.y && z == other.z);
		}

		inline bool operator != (const vector3<Type>& other) const
		{
			return (x != other.x || y != other.y || z != other.z);
		}

		Type& operator [](uint32_t index)
		{
			GMATH_ASSERT(index < 3 && index >= 0, "Out of range index!");
			return (((Type*)this)[index]);
		}

		Type* data() const
		{
			return (Type*)this;
		}

		inline GMATH_LENGTH length() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		inline vector3<Type> normalized() const
		{
			return vector3<Type>(x / length(), y / length(), z / length());
		}

		static inline vector3<Type> normalize(const vector3<Type>& vec)
		{
			return vec.normalized();
		}

		inline Type dot(const vector3<Type>& other)
		{
			return x * other.x + y * other.y + z * other.z;
		}

		static inline Type dot(const vector3<Type>& a, const vector3<Type>& b)
		{
			return a.dot(b);
		}

		inline vector3<Type> cross(const vector3<Type>& other)
		{
			return vector3<Type>(
					y * other.z - z * other.y,
					z * other.x - x * other.z,
					x * other.y - y * other.x
					);
		}

		static inline vector3<Type> cross(const vector3<Type>& a, const vector3<Type>& b)
		{
			return a.cross(b);
		}

		static inline GMATH_ANGLE angleBetween(const vector3<Type>& a, const vector3<Type>& b)
		{
			return acos((GMATH_ANGLE)dot(a, b) / (a.length() * b.length()));
		}

		inline friend std::ostream& operator << (std::ostream& out, const vector3<Type>& vec)
		{
			out << "[" << vec.x << ":" << vec.y << ":" << vec.z << "]";

			return out;
		}
	};
}

#endif //GMATH_VECTOR3_HPP
