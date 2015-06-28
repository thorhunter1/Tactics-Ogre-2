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

int RenderableObject::bindRenderImage( const sf::Image& image )
{
    renderImage_ = image;
}


