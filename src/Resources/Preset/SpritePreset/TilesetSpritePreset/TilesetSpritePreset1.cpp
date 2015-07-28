#include <iostream>

#include "SFML.hpp"
#include "TilesetSpritePreset1.hpp"

#include "Utils.hh"

sf::Sprite TilesetSpritePreset1::getSprite( unsigned int frameID )
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

sf::Sprite TilesetSpritePreset1::getSprite( 
		Tileset::Cliff cliff, 
		Orientation orient,
		Tileset::Weight weight,
	        Tileset::CliffType cliffType )
{
	int tmp_id = 0;

	if( cliff == Tileset::Cliff::Top )  
	{
		if( cliffType == Tileset::CliffType::Rugged )	tmp_id += 0;
		if( cliffType == Tileset::CliffType::Smooth )   tmp_id += 2;
	}

	if( cliff == Tileset::Cliff::None )
	{
		if( weight == Tileset::Weight::Small ) 	tmp_id += 6;
		if( weight == Tileset::Weight::Medium ) tmp_id += 4;
		if( weight == Tileset::Weight::Large )  tmp_id += 8;
		if( weight == Tileset::Weight::Full ) 	tmp_id += 10;
	}

	if( orient == Orientation::North ) tmp_id += 0;
	if( orient == Orientation::East )  tmp_id += 1;
	if( orient == Orientation::South ) tmp_id += spriteHorizontalCount_ + 1;
	if( orient == Orientation::West )  tmp_id += spriteHorizontalCount_;

	return getSprite( tmp_id );

}
