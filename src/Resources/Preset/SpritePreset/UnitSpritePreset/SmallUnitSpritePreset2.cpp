//#include <>
#include <iostream>

#include "SFML.hpp"
#include "SmallUnitSpritePreset2.hpp"

#include "Utils/Debug/DebugUtils.hpp"

sf::Sprite SmallUnitSpritePreset2::getSprite( unsigned int frameID )
{
    int bonusWidth = 0;
    int bonusOffset = 0;

    if( frameID >= spriteHorizontalCount_ * spriteVerticalCount_ )
        TraceError( "Frame ID " << frameID << " outside range" );

    sf::IntRect frame_rect= sf::IntRect( 
          frameWidth_ * ( frameID % spriteHorizontalCount_ ) + bonusOffset,
          frameHeight_ * ( frameID / spriteHorizontalCount_ ),
          frameWidth_ + bonusWidth,
          frameHeight_ );

    sf::Sprite temp_sprite = sf::Sprite();

    temp_sprite.setTextureRect( frame_rect );

    return temp_sprite;
}
