#ifndef ISOMETRIC_MAP_UTILS_HPP
#define ISOMETRIC_MAP_UTILS_HPP

#include "Isometry.hh"
#include "Utils.hh"

namespace Isometry
{
	// Makes tile fit into adjacent tiles
	int smoothTile( IsometricMap& map, int x, int y, int z );
	int smoothTile( IsometricMap& map, Orientation orient, int x, int y, int z );

	// Smooth whole map
	int smoothMap( IsometricMap& map );

	// Gets adjacent tile to specified
	IsometricTile* getAdjacentTile( IsometricMap& map, Orientation orient, int x, int y, int z );

	// Returns the visibility configuration of tile
	Tileset::Visibility checkVisibility( IsometricMap& map, IsometricTile* tile );

}

#endif //ISOMETRIC_MAP_UTILS_HPP
