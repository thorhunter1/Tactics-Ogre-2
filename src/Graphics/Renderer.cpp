#include "Graphics/Renderer.hpp"

#include "SFML.hpp"

#include "Utils.hh"
#include "Resources.hh"
#include "Graphics.hh"
#include "Isometry.hh"

int Renderer::init()
{
	Renderer& r = Renderer::getInstance();
	r._init();
}

int Renderer::render( RenderableObject* obj, int x, int y )
{
	Renderer& r = Renderer::getInstance();
	r._render( obj, x, y );
}

int Renderer::render( IsometricTile* tile, Tileset::Visibility vis, int off_x, int off_y )
{
	Renderer& r = Renderer::getInstance();
	r._render( tile, vis, off_x, off_y );
}

int Renderer::render( IsometricTileComposite& composite, int off_x, int off_y )
{
	Renderer& r = Renderer::getInstance();
	for( int i = 0; i < composite.getSize(); ++i )
	{
		IsometricTile* tmp_tile = composite.getTile( i );
		if( tmp_tile != NULL )
		{
			r._render( tmp_tile, Tileset::Visibility::All, off_x, off_y );
		}
	}
}

int Renderer::render( IsometricMap& map, int off_x, int off_y )
{
	Renderer& r = Renderer::getInstance();
	r._render( map, off_x, off_y );
}

int Renderer::clear()
{
	Renderer& r = Renderer::getInstance();
	r._clear();
}

int Renderer::_init()
{
	window_.create( sf::VideoMode( 800, 600 ), "My window", sf::Style::Close );
}

int Renderer::_render( RenderableObject* obj, int x, int y )
{
	if( obj->fUpdateTexture_ )
	{
		sf::Image image = obj->renderImage_;
		Graphics::teamColor( image, obj->teamColor_ );
		obj->updateTexture( image );
	}

	sf::Sprite sprite = obj->getRenderSprite();
	sprite.setPosition( x, y );
	sprite.setScale( 2, 2 );

	window_.draw( sprite );

	return 0;
}

int Renderer::_render( IsometricTile* tile, Tileset::Visibility vis, int off_x, int off_y, bool rendTile, bool rendCliff )
{
	_render( tile, vis, off_x, off_y, rendTile, rendCliff, Orientation::North );
	_render( tile, vis, off_x, off_y, rendTile, rendCliff, Orientation::South );
	_render( tile, vis, off_x, off_y, rendTile, rendCliff, Orientation::West );
	_render( tile, vis, off_x, off_y, rendTile, rendCliff, Orientation::East );
}

int Renderer::_render( IsometricTile* tile, Tileset::Visibility vis, int off_x, int off_y, bool rendTile, bool rendCliff, Orientation orient )
{
	const int offset = 16;

	sf::Sprite sprite1 = tile->getRenderTileSprite( orient );
	sf::Sprite cliff1 = tile->getRenderCliffSprite( orient );

#define X_ISOMETRIC_COEFF 2 * offset * (tile->coordinates.x - tile->coordinates.y)
#define Y_ISOMETRIC_COEFF -offset * (tile->coordinates.x + tile->coordinates.y + tile->coordinates.z)

	int x_coeff, y_coeff;

	if( orient == Orientation::North )
	{
		x_coeff = -2 * offset + off_x;
		y_coeff = -offset + off_y;
	}
	else if( orient == Orientation::South )
	{
		x_coeff = 0 + off_x;
		y_coeff = 0 + off_y;
	}
	else if( orient == Orientation::West )
	{
		x_coeff = -2 * offset + off_x;
		y_coeff = 0 + off_y;
	}
	else if( orient == Orientation::East )
	{
		x_coeff = 0 + off_x;
		y_coeff = -offset + off_y;
	}

	if( rendTile )
	{
		sprite1.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		sprite1.setScale( 2, 2 );
	}

	if( rendCliff )
	{
		cliff1.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		cliff1.setScale( 2, 2 );
	}

#undef X_ISOMETRIC_COEFF
#undef Y_ISOMETRIC_COEFF


	Tileset::Visibility orient_vis;
	if( orient == Orientation::North ) orient_vis = Tileset::Visibility::CliffNorth | Tileset::Visibility::TileNorth;
	if( orient == Orientation::South ) orient_vis = Tileset::Visibility::CliffSouth | Tileset::Visibility::TileSouth;
	if( orient == Orientation::West ) orient_vis = Tileset::Visibility::CliffWest | Tileset::Visibility::TileWest;
	if( orient == Orientation::East ) orient_vis = Tileset::Visibility::CliffEast | Tileset::Visibility::TileEast;

	if( rendCliff )
	{
		if( vis & orient_vis ) window_.draw( cliff1 );
	}
	if( rendTile )
	{
		if( vis & orient_vis ) window_.draw( sprite1 );
	}
}



int Renderer::_render( IsometricMap& map, int off_x, int off_y )
{
	sf::Vector3f map_size = map.getSize();

	
	for( int iHeight = 0; iHeight < map_size.z; ++iHeight )
	{

	for( int iLayer = 0; iLayer < 3; ++iLayer )
	{
		for( int iWidth = map_size.x - 1; iWidth >= 0; --iWidth )
		{
			for( int iLength = map_size.y - 1; iLength >= 0; --iLength )
			{
				
				//for( int iHeight = 0; iHeight < map_size.z; ++iHeight )
				//{
					//TODO: perhaps move visibility to isometricObject/tile member?

					IsometricTile* main_tile = map.getTile( iWidth, iLength, iHeight );
					if( main_tile == NULL ) { continue; }

					Tileset::Visibility vis = _checkVisibility( main_tile, &map );
			
					if( iLayer == 0 ) 
						_render( main_tile, vis, off_x, off_y, true, true );
					else if( iLayer == main_tile->getLayer() )
						_render( main_tile, vis, off_x, off_y, true, false );
				}

			}
		}
	}
}

Tileset::Visibility Renderer::_checkVisibility( IsometricTile* tile, IsometricMap* map )
{

	Tileset::Visibility vis = Tileset::Visibility::All;

	if( tile == NULL || map == NULL ) return ~vis;

	int x = tile->coordinates.x;
	int y = tile->coordinates.y;
	int z = tile->coordinates.z;

	IsometricTile* south_tile = Isometry::getAdjacentTile( map, Orientation::South, x, y, z );
	IsometricTile* west_tile = Isometry::getAdjacentTile( map, Orientation::West, x, y, z );
	IsometricTile* top_tile = map->getTile( x, y, z + 1 );

	if( south_tile != NULL ) vis &= ( ~Tileset::Visibility::CliffSouth );
	if( west_tile != NULL ) vis &= ( ~Tileset::Visibility::CliffWest );
	if( top_tile != NULL ) vis &= ( ~Tileset::Visibility::TileAll );

	return vis;
}

int Renderer::_clear()
{
	window_.display();
	window_.clear( sf::Color( 56, 155, 155, 255 ) );
}

