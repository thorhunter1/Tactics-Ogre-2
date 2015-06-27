#include "RenderableObject.hpp"
/*
RenderableObject::RenderableObject( const RenderableObject& obj ) :
    renderTexture_( obj.renderTexture_ ),
    renderSprite_( obj.renderSprite_ ),
    teamColor_( obj.teamColor_ )
{

}

RenderableObject RenderableObject::getRenderCopy()
{
    RenderableObject obj( *this );
    return obj;
}
*/
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

int RenderableObject::loadRenderImage( const sf::Image& image )
{
    renderImage_ = image;
}


