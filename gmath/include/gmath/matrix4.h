#ifndef GMATH_MATRIX4_H
#define GMATH_MATRIX4_H

#include "shared.hpp"
#include "vector4.hpp"

namespace gmath
{
	template <typename Type>
	struct matrix4
	{
        // Matrix's data can be accessed in several ways
		union
		{
			Type data[16];
			Type mat[4][4];
			vector4<Type> vec[4];
		};

        //////////////////////////////////////////////
		//			CONSTRUCTORS					//
		//////////////////////////////////////////////
		matrix4()
			: vec {vector4<Type>(),vector4<Type>(),vector4<Type>(),vector4<Type>()}
		{}

		matrix4(Type identity)
			: data {
				identity, (Type)0, (Type)0, (Type)0,
				(Type)0, identity, (Type)0, (Type)0,
				(Type)0, (Type)0, identity, (Type)0,
				(Type)0, (Type)0, (Type)0, identity}
		{}

		matrix4(const vector4<Type>& a, const vector4<Type>& b, const vector4<Type>& c, const vector4<Type>& d)
			: vec {a, b, c, d}
		{}

		matrix4(Type m11, Type m12, Type m13, Type m14,
				Type m21, Type m22, Type m23, Type m24,
				Type m31, Type m32, Type m33, Type m34,
				Type m41, Type m42, Type m43, Type m44)
			: data {m11, m12, m13, m14,
					m21, m22, m23, m24,
					m31, m32, m33, m34,
					m41, m42, m43, m44}
		{}


        //////////////////////////////////////////////
		//			OPERATOR OVERLOADS				//
		//////////////////////////////////////////////
		inline matrix4<Type> operator + (const matrix4<Type>& other) const
		{
			return matrix4<Type>(
					vec[0] + other.vec[0],
					vec[1] + other.vec[1],
					vec[2] + other.vec[2],
					vec[3] + other.vec[3]
					);
		}

		inline matrix4<Type> operator - (const matrix4<Type>& other) const
		{
			return matrix4<Type>(
					vec[0] - other.vec[0],
					vec[1] - other.vec[1],
					vec[2] - other.vec[2],
					vec[3] - other.vec[3]
			);
		}

        matrix4<Type> operator * (const matrix4<Type>& other) const
        {
            matrix4<Type> result;

            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    for(int k = 0; k < 4; k++)
                        result.mat[i][j] += mat[i][k] * other.mat[k][j];

            return result;
        }

		inline vector4<Type>& operator [] (uint32_t index)
		{
			GMATH_ASSERT(index >= 0 && index < 4, "Out of range index!");
			return vec[index];
		}

        matrix4<Type> transposed() const
        {
            matrix4<Type> result;
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    result.mat[i][j] = mat[j][i];

            return result;
        }
	};
}

#endif //GMATH_MATRIX4_H
