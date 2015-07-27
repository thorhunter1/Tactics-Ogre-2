#include "IsometricMapUtils.hpp"

namespace Isometry
{

	int smoothMap( IsometricMap* map )
	{
		Debug( map->getSize().z );
		for( int iWidth = 0; iWidth < map->getSize().x; ++iWidth )
		{
			for( int iLength = 0; iLength < map->getSize().y; ++iLength )
			{
				for( int iHeight = 0; iHeight < map->getSize().z; ++iHeight )
				{
					IsometricTile* main_tile = map->getTile( iWidth, iLength, iHeight );
					if( main_tile == NULL ) continue;

					IsometricTile* up_tile = map->getTile( iWidth, iLength, iHeight -1 );
					IsometricTile* down_tile = map->getTile( iWidth, iLength, iHeight +1 );
					IsometricTile* north_tile = map->getTile( iWidth, iLength +1, iHeight );
					IsometricTile* south_tile = map->getTile( iWidth, iLength -1, iHeight );
					IsometricTile* west_tile = map->getTile( iWidth -1, iLength, iHeight );
					IsometricTile* east_tile = map->getTile( iWidth +1, iLength, iHeight );

					IsometricTile* up_north_tile = map->getTile( iWidth, iLength +1, iHeight +1 );
					IsometricTile* up_south_tile = map->getTile( iWidth, iLength -1, iHeight +1 );
					IsometricTile* up_west_tile = map->getTile( iWidth -1, iLength, iHeight +1 );
					IsometricTile* up_east_tile = map->getTile( iWidth +1, iLength, iHeight +1 );

					// ==Tile & Cliff visibility==
					Tileset::Visibility vis = Tileset::Visibility::All;
					if( south_tile != NULL ) vis & ( ~Tileset::Visibility::CliffSouth );
					if( west_tile != NULL ) vis & ( ~Tileset::Visibility::CliffWest );
					if( up_tile != NULL ) vis & ( ~Tileset::Visibility::TileAll );

					//  ==Tile smoothing==
					
					// North
					if( north_tile != NULL && up_north_tile == NULL )
					{
						if( north_tile->getTileType() == main_tile->getTileType() )
							main_tile->setWeight( Tileset::Weight::Medium, Orientation::North );
						else
							main_tile->setWeight( Tileset::Weight::Small, Orientation::North );
					}

					// South
					if( south_tile != NULL && up_south_tile == NULL )
					{
						if( south_tile->getTileType() == main_tile->getTileType() )
							main_tile->setWeight( Tileset::Weight::Medium, Orientation::South );
						else
							main_tile->setWeight( Tileset::Weight::Small, Orientation::South );
					}

					// West
					if( west_tile != NULL && up_west_tile == NULL )
					{
						if( west_tile->getTileType() == main_tile->getTileType() )
							main_tile->setWeight( Tileset::Weight::Medium, Orientation::West );
						else
							main_tile->setWeight( Tileset::Weight::Small, Orientation::West );
					}

					// East
					if( east_tile != NULL && up_east_tile == NULL )
					{
						if( east_tile->getTileType() == main_tile->getTileType() )
							main_tile->setWeight( Tileset::Weight::Medium, Orientation::East );
						else
							main_tile->setWeight( Tileset::Weight::Small, Orientation::East );
					}

					//  ==Cliff smoothing==
					//
					//North
					if( north_tile == NULL ) main_tile->setCliff( Tileset::Cliff::Top, Orientation::North );
					else main_tile->setCliff( Tileset::Cliff::None, Orientation::North );

					//South
					if( south_tile == NULL ) main_tile->setCliff( Tileset::Cliff::Top, Orientation::South );
					else main_tile->setCliff( Tileset::Cliff::None, Orientation::South );

					//West
					if( west_tile == NULL ) main_tile->setCliff( Tileset::Cliff::Top, Orientation::West );
					else main_tile->setCliff( Tileset::Cliff::None, Orientation::West );

					//East
					if( east_tile == NULL ) main_tile->setCliff( Tileset::Cliff::Top, Orientation::East );
					else main_tile->setCliff( Tileset::Cliff::None, Orientation::East );

				}
			}
		}

	}

}
