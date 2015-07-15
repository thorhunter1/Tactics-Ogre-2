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

int Renderer::render( IsometricTile* tile, int off_x, int off_y, int off_z )
{
	Renderer& r = Renderer::getInstance();
	r._render( tile, off_x, off_y, off_z );
}

int Renderer::render( IsometricTileComposite& composite, int off_x, int off_y, int off_z )
{
    Renderer& r = Renderer::getInstance();
    for( int i = 0; i < composite.getSize(); ++i )
    {
            IsometricTile* tmp_tile = composite.getTile( i );
            if( tmp_tile != NULL )
                r._render( tmp_tile, off_x, off_y, off_z );
    }
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

int Renderer::_render( IsometricTile* tile, int off_x, int off_y, int off_z )
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

	int x_coeff = -2 * offset;
	int y_coeff = -offset;
	sprite1.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
	sprite1.setScale( 2, 2 );

	x_coeff = 0;
	y_coeff = 0;
	sprite2.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
	sprite2.setScale( 2, 2 );

	x_coeff = -2 * offset;
	y_coeff = 0;
	sprite3.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
	sprite3.setScale( 2, 2 );

	x_coeff = 0;
	y_coeff = -offset;
	sprite4.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
	sprite4.setScale( 2, 2 );

    x_coeff = -2 * offset;
    y_coeff = -offset;
    cliff1.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
    cliff1.setScale( 2, 2 );

    x_coeff = 0;
    y_coeff = 0;
    cliff2.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
    cliff2.setScale( 2, 2 );

    x_coeff = -2 * offset;
    y_coeff = 0;
    cliff3.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
    cliff3.setScale( 2, 2 );

    x_coeff = 0;
    y_coeff =  -offset;
    cliff4.setPosition( off_x + x_coeff + X_ISOMETRIC_COEFF, off_y + y_coeff + Y_ISOMETRIC_COEFF );
    cliff4.setScale( 2, 2 );

	#undef X_ISOMETRIC_COEFF
	#undef Y_ISOMETRIC_COEFF


    window_.draw( cliff1 );
    window_.draw( cliff2 );
    window_.draw( cliff3 );
    window_.draw( cliff4 );
	window_.draw( sprite1 );
	window_.draw( sprite2 );
	window_.draw( sprite3 );
	window_.draw( sprite4 );
}

int Renderer::_clear()
{
	window_.display();
	window_.clear();
}

