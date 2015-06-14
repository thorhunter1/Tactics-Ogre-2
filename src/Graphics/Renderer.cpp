#include "Graphics/Renderer.hpp"
#include "Utils/Graphics/ImageUtils.hpp"

int Renderer::render( RenderableObject* obj, int x, int y )
{
    if( obj->fUpdateTexture_ )
    {
        sf::Image image = obj->renderImage_;
        Graphics::teamColor( image, obj->teamColor_ );

        obj->fUpdateTexture = false;
    }

    return 0;
}

