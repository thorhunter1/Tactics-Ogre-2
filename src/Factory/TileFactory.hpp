#ifndef TILE_FACTORY_HPP
#define TILE_FACTORY_HPP

#include "Isometry/IsometricTile.hpp"

class TileFactory
{
	public:
		static IsometricTile* create( const std::string& type );
		static IsometricTile* get( unsigned int ID );
		static int remove( unsigned int ID );
		static int remove( IsometricTile* tile );

	protected:
		static inline TileFactory& getInst() { static TileFactory f; return f; }

	private:
		unsigned int TileCount_ = 0;
		std::vector< IsometricTile* > managedTiles_;
};

#endif //TILE_FACTORY_HPP
