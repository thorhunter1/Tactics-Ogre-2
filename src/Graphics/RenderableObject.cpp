#include "RenderableObject.hpp"


RenderableObject::RenderableObject()
{
    renderSprite_.setTexture( renderTexture_ );
}

int RenderableObject::setTeamColor( TeamColor color )
{
    if( teamColor_ != color )
    {
        teamColor_ = color;
        fUpdateTexture_ = true;
    }
}

sf::Sprite RenderableObject::getRenderSprite()
{
    return renderSprite_;
}

int RenderableObject::setRenderSprite( const sf::Sprite& sprite )
{
	renderSprite_ = sprite;
    renderSprite_.setTexture( renderTexture_ );
}

sf::Sprite RenderableObject::d_getTextureSprite()
{
	sf::Sprite tmp_sprite( renderTexture_ );
	return tmp_sprite;
}

int RenderableObject::updateTexture()
{
    fUpdateTexture_ = false;
    renderTexture_.loadFromImage( renderImage_ );
}

int RenderableObject::updateTexture( const sf::Image& image )
{
    fUpdateTexture_ = false;
    renderTexture_.loadFromImage( image );
}

int RenderableObject::updateTexture( const sf::Uint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y )
{
	renderTexture_.update( pixels, width, height, x, y );
}

int RenderableObject::bindRenderImage( const sf::Image& image )
{
    renderImage_ = image;
}


