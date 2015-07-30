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

    tileMap_[tile->getPosition().x][tile->getPosition().y][tile->getPosition().z] = tile;
}

int IsometricMap::add( IsometricTile* tile, int x, int y, int z )
{
    if( tile != NULL )
    {
        tile->setPosition( x, y, z );
    }
    else TraceReturn( -1, "Omitting nonexisting tile" );

    tileMap_[x][y][z] = tile;
}

int IsometricMap::add( IsometricTileComposite* comp, int off_x, int off_y, int off_z )
{
    for( int i = 0; i < comp->getSize(); ++i )
    {
        IsometricTile* tmp_tile = comp->getTile( i );
        tmp_tile->move( off_x, off_y, off_z );
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

int IsometricMap::remove( int x, int y, int z )
{
	tileMap_[x][y][z] = NULL;
}

int IsometricMap::remove( int x, int y, int z, int width, int length, int height )
{
	for( int iWidth = x; iWidth < x + width; ++iWidth )
		for( int iLength = y; iLength < y + length; ++iLength )
			for( int iHeight = z; iHeight < z + height; ++iHeight )
				tileMap_[iWidth][iLength][iHeight] = NULL;
}


