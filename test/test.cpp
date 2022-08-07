#include "gmath/gmath.hpp"
#include <iostream>


int main()
{
	gmath::vector2<float> vec(7.2f, 5.0f);
	std::cout << vec[0] << "\n";
	vec += {4.2f, 1.9f};
	std::cout << vec << std::endl;

	std::cout << "Angle between two angles in degrees : " << gmath::toDegrees(
			gmath::vector2<float>::angleBetween({1.0f, 0.0f}, {1.0f})) << "\n";

	return 0;
}