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
	const int offset = 16;

	sf::Sprite sprite1 = tile->getRenderTileSprite( Orientation::North );
	sf::Sprite sprite2 = tile->getRenderTileSprite( Orientation::South );
	sf::Sprite sprite3 = tile->getRenderTileSprite( Orientation::West );
	sf::Sprite sprite4 = tile->getRenderTileSprite( Orientation::East );

	sf::Sprite cliff1 = tile->getRenderCliffSprite( Orientation::North );
	sf::Sprite cliff2 = tile->getRenderCliffSprite( Orientation::South );
	sf::Sprite cliff3 = tile->getRenderCliffSprite( Orientation::West );
	sf::Sprite cliff4 = tile->getRenderCliffSprite( Orientation::East );

	//  N     .      E
	//    .   |   .  
	// ._____1|4_____.
	//  ` .  3|2  . `
	//       .|.     
	//  W     `  	 s

#define X_ISOMETRIC_COEFF 2 * offset * (tile->coordinates.x - tile->coordinates.y)
#define Y_ISOMETRIC_COEFF -offset * (tile->coordinates.x + tile->coordinates.y + tile->coordinates.z)

	int x_coeff, y_coeff;

	if( rendTile )
	{
		x_coeff = -2 * offset + off_x;
		y_coeff = -offset + off_y;
		sprite1.setPosition( x_coeff + X_ISOMETRIC_COEFF, + y_coeff + Y_ISOMETRIC_COEFF );
		sprite1.setScale( 2, 2 );

		x_coeff = 0 + off_x;
		y_coeff = 0 + off_y;
		sprite2.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		sprite2.setScale( 2, 2 );

		x_coeff = -2 * offset + off_x;
		y_coeff = 0 + off_y;
		sprite3.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		sprite3.setScale( 2, 2 );

		x_coeff = 0 + off_x;
		y_coeff = -offset + off_y;
		sprite4.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		sprite4.setScale( 2, 2 );
	}

	if( rendCliff )
	{
		x_coeff = -2 * offset + off_x;
		y_coeff = -offset + off_y;
		cliff1.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		cliff1.setScale( 2, 2 );

		x_coeff = 0 + off_x;
		y_coeff = 0 + off_y;
		cliff2.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		cliff2.setScale( 2, 2 );

		x_coeff = -2 * offset + off_x;
		y_coeff = 0 + off_y;
		cliff3.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		cliff3.setScale( 2, 2 );

		x_coeff = 0 + off_x;
		y_coeff =  -offset + off_y;
		cliff4.setPosition( x_coeff + X_ISOMETRIC_COEFF, y_coeff + Y_ISOMETRIC_COEFF );
		cliff4.setScale( 2, 2 );
	}

#undef X_ISOMETRIC_COEFF
#undef Y_ISOMETRIC_COEFF


	if( rendCliff )
	{
		if( vis & Tileset::Visibility::CliffNorth ) window_.draw( cliff1 );
		if( vis & Tileset::Visibility::CliffSouth ) window_.draw( cliff2 );
		if( vis & Tileset::Visibility::CliffWest ) window_.draw( cliff3 );
		if( vis & Tileset::Visibility::CliffEast ) window_.draw( cliff4 );
	}
	if( rendTile )
	{
		if( vis & Tileset::Visibility::TileNorth ) window_.draw( sprite1 );
		if( vis & Tileset::Visibility::TileSouth ) window_.draw( sprite2 );
		if( vis & Tileset::Visibility::TileWest ) window_.draw( sprite3 );
		if( vis & Tileset::Visibility::TileEast ) window_.draw( sprite4 );
	}
}

int Renderer::_render( IsometricMap& map, int off_x, int off_y )
{
	sf::Vector3f map_size = map.getSize();

	for( int iLayer = 0; iLayer < 3; ++iLayer )
	{
		for( int iWidth = map_size.x - 1; iWidth >= 0; --iWidth )
		{
			for( int iLength = map_size.y - 1; iLength >= 0; --iLength )
			{
				for( int iHeight = 0; iHeight < map_size.z; ++iHeight )
				{
					//TODO: perhaps move visibility to isometricObject/tile member?
					Tileset::Visibility vis = Tileset::Visibility::All;

					IsometricTile* main_tile = map.getTile( iWidth, iLength, iHeight );
					if( main_tile == NULL ) { continue; }
					IsometricTile* south_tile = map.getTile( iWidth - 1, iLength, iHeight );
					IsometricTile* west_tile = map.getTile( iWidth, iLength - 1, iHeight );
					IsometricTile* top_tile = map.getTile( iWidth, iLength, iHeight + 1 );

					//else Debug( "NOT NULL" );
					if( south_tile != NULL ) vis & ( ~Tileset::Visibility::CliffSouth );
					if( west_tile != NULL ) vis & ( ~Tileset::Visibility::CliffWest );
					if( top_tile != NULL ) vis & ( ~Tileset::Visibility::TileAll );

					if( main_tile->getLayer() == iLayer ) 
						_render( main_tile, vis, off_x, off_y, true, true );
					else
						_render( main_tile, vis, off_x, off_y, false, true );
				}

			}
		}
	}
}

int Renderer::_clear()
{
	window_.display();
	window_.clear( sf::Color( 56, 155, 155, 255 ) );
}

