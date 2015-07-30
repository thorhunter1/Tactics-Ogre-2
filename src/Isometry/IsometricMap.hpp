#ifndef ISOMETRIC_MAP_HPP
#define ISOMETRIC_MAP_HPP

#include "SFML.hpp"

class IsometricTile;
class IsometricTileComposite;

class IsometricMap
{
	public:

		// Map size
        	int setSize( int x, int y, int z );
		sf::Vector3f getSize();

		// Add tile components
		int add( IsometricTile* tile );
		int add( IsometricTile* tile, int x, int y, int z );
		int add( IsometricTileComposite* comp, int off_x = 0, int off_y = 0, int off_z = 0 );

		// Get tile components
		IsometricTile* getTile( int x, int y );
		IsometricTile* getTile( int x, int y, int z );

		// Remove tile components
		int remove( int x, int y, int z );
		int remove( int x, int y, int z, int width, int length, int height );

		// Move tile
		int move( int x_src, int y_src, int z_src, int x_dest, int y_dest, int z_dest, bool replaceOld = false );

	protected:

        	sf::Vector3f size_;
		std::map< int, std::map< int, std::map< int, IsometricTile* > > > tileMap_;
};

#endif //ISOMETRIC_MAP_HPP
