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
                sf::IntRect( rect.left + rect.width, 0, -rect.width, rect.height )
                );
        rect = sprite.getTextureRect();
    }

}


#endif //SPRITE_UTILS_HPP
