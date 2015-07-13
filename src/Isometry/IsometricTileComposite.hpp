#ifndef ISOMETRIC_TILE_COMPOSITE_HPP
#define ISOMETRIC_TILE_COMPOSITE_HPP

#include "SFML.hpp"

class IsometricTile;

class IsometricTileComposite
{
	public:

		int add( IsometricTile* tile );
		int add( IsometricTile* tile, int x, int y, int z );

        IsometricTile* getTile( int iter );
		IsometricTile* getTile( int x, int y );
		IsometricTile* getTile( int x, int y, int z );

        unsigned int getSize();

	protected:

        sf::Vector3f coordinates_;
        std::vector< IsometricTile* > tileComposite_;
};

#endif //ISOMETRIC_TILE_COMPISITE_HPP
