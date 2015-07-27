#ifndef ISOMETRIC_MAP_UTILS_HPP
#define ISOMETRIC_MAP_UTILS_HPP

#include "Isometry.hh"
#include "Utils.hh"

namespace Isometry
{
    int smoothTile( IsometricMap* map, int x, int y, int z );
	int smoothMap( IsometricMap* map );
    IsometricTile* getAdjacentTile( IsometricMap* map, Orientation orient, int x, int y, int z );

    int _smoothTile( IsometricMap* map, Orientation orient, int x, int y, int z ); 
}

#endif //ISOMETRIC_MAP_UTILS_HPP
