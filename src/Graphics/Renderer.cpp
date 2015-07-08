#include "Graphics/Renderer.hpp"
#include "Utils/Graphics/ImageUtils.hpp"
#include "Utils/Debug/DebugUtils.hpp"

#include "SFML.hpp"

#include "Resources/Preset/SpritePreset/TilesetSpritePreset/TilesetSpritePreset1.hpp"

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

	sprite1.setPosition( off_x - 2 * offset, off_y - offset );
	sprite1.setScale( 2, 2 );

	sprite2.setPosition( off_x, off_y );
	sprite2.setScale( 2, 2 );

	sprite3.setPosition( off_x - 2 * offset, off_y );
	sprite3.setScale( 2, 2 );

	sprite4.setPosition( off_x, off_y - offset );
	sprite4.setScale( 2, 2 );

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

