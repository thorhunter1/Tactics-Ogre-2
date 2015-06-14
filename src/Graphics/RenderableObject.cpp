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

sf::Sprite RenderableObject::getRenderSprite()
{
    return renderSprite_;
}

int RenderableObject::updateTexture()
{
    fUpdateTexture_ = false;
}

int RenderableObject::loadRenderImage( const sf::Image& image )
{
    renderImage_ = image;
}


