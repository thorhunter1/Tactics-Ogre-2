#ifndef SPRITE_UTILS_HPP
#define SPRITE_UTILS_HPP

#include "SFML.hpp"
#include "Utils/Debug/DebugUtils.hpp"

namespace Graphics
{
    //flips X coordinates
    int flipX( sf::Sprite &sprite )
    {
        sf::IntRect rect = sprite.getTextureRect();

        sprite.setTextureRect( 
                sf::IntRect( rect.left + rect.width, rect.top, -rect.width, rect.height )
               );
        //sprite.scale( -1.0f, 1.0f );
    }

}


#endif //SPRITE_UTILS_HPP
