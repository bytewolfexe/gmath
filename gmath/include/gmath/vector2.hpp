#ifndef GMATH_VECTOR2_HPP
#define GMATH_VECTOR2_HPP

#include "shared.hpp"


namespace gmath
{
	template <typename Type>
	struct vector2
	{
		Type x, y;


		//////////////////////////////////////////////
		//			CONSTRUCTORS					//
		//////////////////////////////////////////////
		vector2()
			: x((Type)0), y((Type)0)
		{}

		vector2(Type fill)
			: x(fill), y(fill)
		{}

		vector2(Type x, Type y)
			: x(x), y(y)
		{}

		//////////////////////////////////////////////
		//			OPERATOR OVERLOADING			//
		//////////////////////////////////////////////

		inline vector2<Type> operator + (const vector2<Type>& other) const
		{
			return vector2<Type>(x + other.x, y + other.y);
		}

		inline vector2<Type> operator - (const vector2<Type>& other) const
		{
			return vector2<Type>(x - other.x, y - other.y);
		}

		inline vector2<Type> operator * (const vector2<Type>& other) const
		{
			return vector2<Type>(x * other.x, y * other.y);
		}

		inline vector2<Type> operator / (const vector2<Type>& other) const
		{
			return vector2<Type>(x / other.x, y / other.y);
		}

		inline vector2<Type>& operator += (const vector2<Type>& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		inline vector2<Type>& operator -= (const vector2<Type>& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		inline vector2<Type>& operator *= (const vector2<Type>& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		inline vector2<Type>& operator /= (const vector2<Type>& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		//////////////////////////////////////////////
		//				OTHER FUNCTIONS				//
		//////////////////////////////////////////////

		// Returns true if two vectors are same
		inline bool operator == (const vector2<Type>& other) const
		{
			return (x == other.x && y == other.y);
		}

		// Returns true if two vectors are different
		inline bool operator != (const vector2<Type>& other) const
		{
			return (x != other.x || y != other.y);
		}

		// Returns magnitude (length) of this vector
		inline GMATH_LENGTH length() const
		{
			return (GMATH_LENGTH)sqrt(x * x + y * y);
		}

		// Returns this vector's normalized vector
		inline vector2<Type> normalized() const
		{
			return vector2<Type>(x / length(), y / length());
		}

		// Returns normalized vector of vector vec
		static inline vector2<Type> normalize(const vector2<Type>& vec)
		{
			return vec.normalized();
		}

		// Returns dot product of this vector and other vector
		inline Type dot(const vector2<Type>& other) const
		{
			return x * other.x + y * other.y;
		}

		// Returns dot product of vectors a and b
		static inline Type dot(const vector2<Type>& a, const vector2<Type>& b)
		{
			return a.dot(b);
		}

		Type& operator [](uint32_t index)
		{
			GMATH_ASSERT(index < 2 && index >= 0, "Out of range index!");
			return (((Type*)this)[index]);
		}

		Type* data() const
		{
			return (Type*)this;
		}

		// Returns angle between two vectors in RADIANS
		static inline GMATH_ANGLE angleBetween(const vector2<Type>& a, const vector2<Type>& b)
		{
			return (GMATH_ANGLE)acos(dot(a, b) / (a.length() * b.length()));
		}

		inline friend std::ostream& operator << (std::ostream& out, const vector2<Type>& vec)
		{
			out << "[" << vec.x << ":" << vec.y << "]";

			return out;
		}
	};
}

#endif //GMATH_VECTOR2_HPP
