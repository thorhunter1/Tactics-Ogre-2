#include "SpriteUtils.hpp"

#include "SFML.hpp"

namespace Graphics
{
    int flipX( sf::Sprite &sprite )
    {
        sf::IntRect rect = sprite.getTextureRect();

        sprite.setTextureRect( 
                sf::IntRect( rect.left + rect.width, rect.top, -rect.width, rect.height )
               );
    }

}


