#include "Graphics/Renderer.hpp"
#include "Utils/Graphics/ImageUtils.hpp"

#include "SFML.hpp"

sf::RenderWindow Renderer::window_;

int Renderer::init()
{
    window_.create( sf::VideoMode( 800, 600 ), "My window", sf::Style::Close );
}

int Renderer::render( RenderableObject* obj, int x, int y )
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

int Renderer::d_render( RenderableObject* obj, int x, int y )
{
	sf::Sprite sprite = obj->d_getTextureSprite();
	sprite.setPosition( x, y );
	sprite.setScale( 2, 2 );

	window_.draw( sprite );
}

int Renderer::clear()
{
    window_.display();
    window_.clear();
}

