#ifndef TILE_COMPOSITE_FACTORY_HPP
#define TILE_COMPOSITE_FACTORY_HPP

#include <string>
#include "SFML.hpp"

class IsometricTileComposite;

class TileCompositeFactory
{
	public:

		static IsometricTileComposite create( const std::string& tileType, int width, int length, int height = 1 );

	protected:

		TileCompositeFactory() {}
		static inline TileCompositeFactory& getInstance() { static TileCompositeFactory f; return f; }

        IsometricTileComposite _create( const std::string& tileType, int width, int length, int height );
	
    private:
};

#endif //TILE_COMPOSITE_FACTORY_HPP
