#ifndef TEXTURE_UTILS_HPP
#define TEXTURE_UTILS_HPP

#include "Graphics/RenderableObject.hpp"
#include "Utils/Debug/DebugUtils.hpp"

#include "SFML.hpp"

namespace Graphics
{
    int dissolve( RenderableObject* obj )
    {
	    static int i = 0;

	    sf::Uint8* pixel = new sf::Uint8[4];
	    pixel[0] = pixel[1] = pixel[2] = pixel[3] = 0;
	    sf::Sprite tmp_sprite = obj->getRenderSprite();
	    sf::IntRect tmp_rect = tmp_sprite.getTextureRect();
	    Debug( tmp_rect.left << " " << tmp_rect.top );
	    Debug( tmp_rect.width << "x" << tmp_rect.height );
	    if( tmp_rect.width < 0 ) { tmp_rect.left += tmp_rect.width; tmp_rect.width*=-1; }
	    obj->updateTexture( pixel, 1, 1, 
			    tmp_rect.left+ (i % (int)tmp_rect.width ), 
			    tmp_rect.top + ( (int) i / tmp_rect.width )
			    );
	    ++i;
	    if( i >= tmp_rect.width * tmp_rect.height ) i = 0;
	    delete pixel;

    }
}

#endif //IMAGE_UTILS_HPP
