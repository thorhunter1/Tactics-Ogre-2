#include "SmallUnitSpritePreset.hpp"

#include <iostream>

#include "SFML.hpp"
#include "Utils.hh"

sf::Sprite SmallUnitSpritePreset::getSprite( unsigned int frameID )
{
    int bonusWidth = ( frameID == 7 || frameID == 16 ) ? 3 : 0;
    int bonusOffset = ( frameID == 8 || frameID == 17 ) ? 3 : 0;

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
