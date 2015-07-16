#ifndef ISOMETRIC_MAP_HPP
#define ISOMETRIC_MAP_HPP

#include "SFML.hpp"

class IsometricTile;
class IsometricTileComposite;

class IsometricMap
{
	public:

        int setSize( int x, int y, int z );
		sf::Vector3f getSize();

		int add( IsometricTile* tile );
		int add( IsometricTile* tile, int x, int y, int z );
		int add( IsometricTileComposite* comp, int off_x = 0, int off_y = 0, int off_z = 0 );

		IsometricTile* getTile( int x, int y );
		IsometricTile* getTile( int x, int y, int z );

	protected:

        sf::Vector3f size_;
		std::map< int, std::map< int, std::map< int, IsometricTile* > > > tileMap_;
};

#endif //ISOMETRIC_MAP_HPP
