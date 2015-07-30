#include "IsometricMapUtils.hpp"

#include <cstdlib>

namespace Isometry
{
	int smoothTile( IsometricMap& map, int x, int y, int z )
	{
		smoothTile( map, Orientation::North, x, y, z );
		smoothTile( map, Orientation::South, x, y, z );
		smoothTile( map, Orientation::West, x, y, z );
		smoothTile( map, Orientation::East, x, y, z );
	}

	int smoothMap( IsometricMap& map )
	{
		for( int iWidth = 0; iWidth < map.getSize().x; ++iWidth )
		{
			for( int iLength = 0; iLength < map.getSize().y; ++iLength )
			{
				for( int iHeight = 0; iHeight < map.getSize().z; ++iHeight )
				{
					smoothTile( map, iWidth, iLength, iHeight ); 
				}
			}
		}
	}

	IsometricTile* getAdjacentTile( IsometricMap& map, Orientation orient, int x, int y, int z )
	{
		IsometricTile* tile = NULL;

		if( orient == Orientation::North )
			tile = map.getTile( x, y+1, z );
		if( orient == Orientation::South )
			tile = map.getTile( x, y-1, z );
		if( orient == Orientation::West )
			tile = map.getTile( x-1, y, z );
		if( orient == Orientation::East )
			tile = map.getTile( x+1, y, z );

		return tile;
	}

	int smoothTile( IsometricMap& map, Orientation orient, int x, int y, int z )
	{
		IsometricTile* main_tile = map.getTile( x, y, z );
		if( main_tile == NULL ) return -1;

		IsometricTile* adj_tile = getAdjacentTile( map, orient, x, y, z );
		IsometricTile* up_adj_tile = getAdjacentTile( map, orient, x, y, z+1 );
		IsometricTile* bot_adj_tile = getAdjacentTile( map, orient, x, y, z-1 );
		IsometricTile* up_tile = map.getTile( x, y, z+1 );
		IsometricTile* bot_tile = map.getTile( x, y, z-1 );

		if( adj_tile != NULL )
		{
			if( up_adj_tile == NULL )
			{
				if( adj_tile->getTileType() == main_tile->getTileType() )
					main_tile->setWeight( Tileset::Weight::Medium, orient );
				else if ( adj_tile->getLayer() < main_tile->getLayer() )
				{
					static int seed = std::time(0);
					++seed;
					std::srand( seed );
					int rand_number = std::rand () % 2;
					Debug( rand_number );
					if( rand_number == 1 )
						main_tile->setWeight( Tileset::Weight::Small, orient );
					else
						main_tile->setWeight( Tileset::Weight::Large, orient );
				}
				else 
					main_tile->setWeight( Tileset::Weight::Full, orient );
			}
			else
				main_tile->setWeight( Tileset::Weight::Small, orient );
		}

		if( adj_tile == NULL && up_tile == NULL && bot_adj_tile != NULL ) 
			main_tile->setCliff( Tileset::Cliff::TopBottom, orient );

		else if( adj_tile == NULL && up_tile == NULL ) 
			main_tile->setCliff( Tileset::Cliff::Top, orient );

		else if( bot_adj_tile != NULL && up_tile != NULL ) 
			main_tile->setCliff( Tileset::Cliff::Bottom, orient );

		else if( up_tile != NULL ) 
			main_tile->setCliff( Tileset::Cliff::Middle, orient );

		else 
			main_tile->setCliff( Tileset::Cliff::None, orient );
	}

	Tileset::Visibility checkVisibility( IsometricMap& map, IsometricTile* tile )
	{

		Tileset::Visibility vis = Tileset::Visibility::All;

		if( tile == NULL ) return ~vis;

		int x = tile->getPosition().x;
		int y = tile->getPosition().y;
		int z = tile->getPosition().z;

		IsometricTile* south_tile = Isometry::getAdjacentTile( map, Orientation::South, x, y, z );
		IsometricTile* west_tile = Isometry::getAdjacentTile( map, Orientation::West, x, y, z );
		IsometricTile* top_tile = map.getTile( x, y, z + 1 );

		if( south_tile != NULL ) vis &= ( ~Tileset::Visibility::CliffSouth );
		if( west_tile != NULL ) vis &= ( ~Tileset::Visibility::CliffWest );
		if( top_tile != NULL ) vis &= ( ~Tileset::Visibility::TileAll );

		return vis;
	}


}
