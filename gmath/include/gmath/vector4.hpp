#ifndef GMATH_VECTOR4_HPP
#define GMATH_VECTOR4_HPP


namespace gmath
{
	template <typename Type>
	struct vector4
	{
		Type x, y, z, w;

		vector4()
			: x((Type)0), y((Type)0), z((Type)0), w((Type)0)
		{}

		vector4(Type fill)
			: x(fill), y(fill), z(fill), w(fill)
		{}

		vector4(Type x, Type y, Type z, Type w)
			: x(x), y(y), z(z), w(w)
		{}

		vector4(const vector2<Type>& xy, Type z, Type w)
			: x(xy.x), y(xy.y), z(z), w(w)
		{}

		vector4(Type x, const vector2<Type>& yz, Type w)
			: x(x), y(yz.x), z(yz.y), w(w)
		{}

		vector4(Type x, Type y, const vector2<Type>& zw)
			: x(x), y(y), z(zw.x), w(zw.y)
		{}

		vector4(const vector3<Type>& xyz, Type w)
			: x(xyz.x), y(xyz.y), z(xyz.z), w(w)
		{}

		vector4(Type x, const vector3<Type>& yzw)
			: x(x), y(yzw.x), z(yzw.y), w(yzw.z)
		{}

		inline vector4<Type> operator + (const vector4<Type>& other) const
		{
			return vector4<Type>(x + other.x, y + other.y, z + other.z, w + other.w);
		}

		inline vector4<Type> operator - (const vector4<Type>& other) const
		{
			return vector4<Type>(x - other.x, y - other.y, z - other.z, w - other.w);
		}

		inline vector4<Type> operator * (const vector4<Type>& other) const
		{
			return vector4<Type>(x * other.x, y * other.y, z * other.z, w * other.w);
		}

		inline vector4<Type> operator / (const vector4<Type>& other) const
		{
			return vector4<Type>(x / other.x, y / other.y, z / other.z, w / other.w);
		}

		inline vector4<Type>& operator += (const vector4<Type>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		inline vector4<Type>& operator -= (const vector4<Type>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		inline vector4<Type>& operator *= (const vector4<Type>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		inline vector4<Type>& operator /= (const vector4<Type>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		inline Type& operator [] (uint32_t index)
		{
			GMATH_ASSERT(index >= 0 && index < 4, "Out of range index!");
			return ((Type*)this)[index];
		}

		Type* data() const
		{
			return (Type*)this;
		}

		inline bool operator == (const vector4<Type>& other) const
		{
			return (x == other.x && y == other.y && z == other.z && w == other.w);
		}

		inline bool operator != (const vector4<Type>& other) const
		{
			return (x != other.x || y != other.y || z != other.z || w != other.w);
		}

		inline GMATH_LENGTH length() const
		{
			return (GMATH_LENGTH)sqrt(x * x + y * y + z * z + w * w);
		}

		inline vector4<Type> normalized() const
		{
			return vector4(x / length(), y / length(), z / length(), w / length());
		}

		static inline vector4<Type> normalize(const vector4<Type>& vec)
		{
			return vec.normalized();
		}

		inline friend std::ostream& operator << (std::ostream& out, const vector4<Type>& vec)
		{
			out << "[" << vec.x << ":" << vec.y	<< ":" << vec.z << ":" << vec.w << "]";

			return out;
		}
	};
}

#endif //GMATH_VECTOR4_HPP
