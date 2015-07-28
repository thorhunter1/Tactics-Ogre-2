#include "IsometricMapUtils.hpp"

namespace Isometry
{
    int smoothTile( IsometricMap* map, int x, int y, int z )
    {
        _smoothTile( map, Orientation::North, x, y, z );
        _smoothTile( map, Orientation::South, x, y, z );
        _smoothTile( map, Orientation::West, x, y, z );
        _smoothTile( map, Orientation::East, x, y, z );
    }

	int smoothMap( IsometricMap* map )
	{
		for( int iWidth = 0; iWidth < map->getSize().x; ++iWidth )
		{
			for( int iLength = 0; iLength < map->getSize().y; ++iLength )
			{
				for( int iHeight = 0; iHeight < map->getSize().z; ++iHeight )
				{
                    smoothTile( map, iWidth, iLength, iHeight ); 
				}
			}
		}
	}

    IsometricTile* getAdjacentTile( IsometricMap* map, Orientation orient, int x, int y, int z )
    {
        IsometricTile* tile = NULL;

        if( orient == Orientation::North )
	        tile = map->getTile( x, y+1, z );
        if( orient == Orientation::South )
		    tile = map->getTile( x, y-1, z );
        if( orient == Orientation::West )
		    tile = map->getTile( x-1, y, z );
        if( orient == Orientation::East )
		    tile = map->getTile( x+1, y, z );

        return tile;
    }

    int _smoothTile( IsometricMap* map, Orientation orient, int x, int y, int z )
    {
        IsometricTile* main_tile = map->getTile( x, y, z );
        if( main_tile == NULL ) return -1;

        IsometricTile* adj_tile = getAdjacentTile( map, orient, x, y, z );
        IsometricTile* up_adj_tile = getAdjacentTile( map, orient, x, y, z+1 );
        IsometricTile* bot_adj_tile = getAdjacentTile( map, orient, x, y, z-1 );
        IsometricTile* up_tile = map->getTile( x, y, z+1 );
        IsometricTile* bot_tile = map->getTile( x, y, z-1 );

        if( adj_tile != NULL )
	{
            if( up_adj_tile == NULL )
            {
			    if( adj_tile->getTileType() == main_tile->getTileType() )
			    	main_tile->setWeight( Tileset::Weight::Medium, orient );
			    else
				    main_tile->setWeight( Tileset::Weight::Small, orient );
            }
            else
                main_tile->setWeight( Tileset::Weight::Small, orient );
	}

	if( adj_tile == NULL && up_tile == NULL && bot_adj_tile != NULL ) main_tile->setCliff( Tileset::Cliff::TopBottom, orient );
        else if( adj_tile == NULL && up_tile == NULL ) main_tile->setCliff( Tileset::Cliff::Top, orient );
	else if( bot_adj_tile != NULL && up_tile != NULL ) main_tile->setCliff( Tileset::Cliff::Bottom, orient );
        else if( up_tile != NULL /*&& bot_tile != NULL*/ ) main_tile->setCliff( Tileset::Cliff::Middle, orient );
        else main_tile->setCliff( Tileset::Cliff::None, orient );
    }

}
