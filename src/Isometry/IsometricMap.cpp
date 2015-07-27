#include "IsometricMap.hpp"

#include "Isometry.hh"
#include "Utils.hh"

int IsometricMap::setSize( int x, int y, int z )
{
    size_.x = x;
    size_.y = y;
    size_.z = z;
}

sf::Vector3f IsometricMap::getSize()
{
    return size_;
}

int IsometricMap::add( IsometricTile* tile )
{
    if( tile == NULL )
    {
        TraceReturn( -1, "Omitted adding nonexisting tile" );
    }

    tileMap_[tile->coordinates.x][tile->coordinates.y][tile->coordinates.z] = tile;
}

int IsometricMap::add( IsometricTile* tile, int x, int y, int z )
{
    if( tile != NULL )
    {
        tile->coordinates.x = x;
        tile->coordinates.y = y;
        tile->coordinates.z = z;
    }
    else Warning( "NULL tile was added" );

    tileMap_[x][y][z] = tile;
}

int IsometricMap::add( IsometricTileComposite* comp, int off_x, int off_y, int off_z )
{
    for( int i = 0; i < comp->getSize(); ++i )
    {
        IsometricTile* tmp_tile = comp->getTile( i );
        tmp_tile->coordinates.x += off_x;
        tmp_tile->coordinates.y += off_y;
        tmp_tile->coordinates.z += off_z;
        add( tmp_tile );
    }
}

IsometricTile* IsometricMap::getTile( int x, int y, int z )
{
    return tileMap_[x][y][z];
}

IsometricTile* IsometricMap::getTile( int x, int y )
{
	int highest_tile_z = getSize().z - 1;

	IsometricTile* tile = NULL;

	while( highest_tile_z >= 0 && tile == NULL )
	{
		IsometricTile* tile = tileMap_[x][y][highest_tile_z];
	}

	if( tile == NULL ) Warning( "Map returned NULL tile on request" );

	return tile;
}


