#ifndef ISOMETRIC_OBJECT_HPP
#define ISOMETRIC_OBJECT_HPP

#include "SFML.hpp"

class IsometricObject
{
	public:
		sf::Vector3f getPosition(){ return coordinates; }
		int setPosition( float x, float y, float z ){ coordinates.x = x; coordinates.y = y; coordinates.z = z; }
		int move( float x, float y, float z = 0 ){ coordinates.x += x; coordinates.y += y; coordinates.z += z; }

	protected:

		sf::Vector3f coordinates;

};

#endif //ISOMETRIC_OBJECT_HPP
