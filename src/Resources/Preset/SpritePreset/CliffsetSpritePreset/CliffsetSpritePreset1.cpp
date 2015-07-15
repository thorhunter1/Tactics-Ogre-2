#include <iostream>

#include "SFML.hpp"
#include "CliffsetSpritePreset1.hpp"

#include "Utils.hh"

sf::Sprite CliffsetSpritePreset1::getSprite( unsigned int frameID )
{
    if( frameID >= spriteHorizontalCount_ * spriteVerticalCount_ )
        TraceError( "Frame ID " << frameID << " outside range" );

    sf::IntRect frame_rect= sf::IntRect( 
          frameWidth_ * ( frameID % spriteHorizontalCount_ ),
          frameHeight_ * ( frameID / spriteHorizontalCount_ ),
          frameWidth_,
          frameHeight_ );

    sf::Sprite temp_sprite = sf::Sprite();

    temp_sprite.setTextureRect( frame_rect );

    return temp_sprite;
}

sf::Sprite CliffsetSpritePreset1::getSprite( 
		Orientation orient,
	    Tileset::Cliff cliff,
        int variation )
{
	int tmp_id = 0;

    if( orient == Orientation::North )
    {
        if( cliff == Tileset::Cliff::Top ) tmp_id += 0;
        else 
        {
            sf::Sprite tmp_sprite;
            tmp_sprite.setTextureRect( sf::IntRect( 0, 0, 1, 1 ) );
            return tmp_sprite;
        }
    }
    if( orient == Orientation::East )
    {
        if( cliff == Tileset::Cliff::Top ) tmp_id += 1;
        else 
        {
             sf::Sprite tmp_sprite;
            tmp_sprite.setTextureRect( sf::IntRect( 0, 0, 1, 1 ) );
            return tmp_sprite;
        }
    }

    if( orient == Orientation::West ) tmp_id += spriteHorizontalCount_;
    if( orient == Orientation::South ) tmp_id += spriteHorizontalCount_ + 1;

    if( cliff == Tileset::Cliff::Top ) tmp_id += 0;
    if( cliff == Tileset::Cliff::Bottom ) tmp_id += spriteHorizontalCount_;
    if( cliff == Tileset::Cliff::Middle ) tmp_id += 2 * spriteHorizontalCount_;

	return getSprite( tmp_id );

}
