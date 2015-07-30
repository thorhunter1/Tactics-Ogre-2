#ifndef TILE_FACTORY_HPP
#define TILE_FACTORY_HPP

#include "Isometry/IsometricTile.hpp"

class TileFactory
{
	public:
		static IsometricTile* create( const std::string& type, int x = 0, int y = 0, int z = 0 );
		static IsometricTile* get( unsigned int ID );
		static int remove( unsigned int ID );
		static int remove( IsometricTile* tile );
		static int updateTileType( IsometricTile* tile, const std::string& type );

		static int load();

	protected:
		TileFactory();
		static inline TileFactory& getInstance() { static TileFactory f; return f; }

	private:
		unsigned int TileCount_ = 0;
		std::vector< IsometricTile* > managedTiles_;

		TilesetSpritePreset* grassPreset_;
		TilesetSpritePreset* dirtPreset_;
		TilesetSpritePreset* longGrassPreset_;

        CliffsetSpritePreset* dummyCliffPreset_;
};

#endif //TILE_FACTORY_HPP
