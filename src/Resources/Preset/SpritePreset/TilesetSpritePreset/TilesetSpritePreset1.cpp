#include <iostream>

#include "SFML.hpp"
#include "Resources/Preset/SpritePreset/TilesetSpritePreset/TilesetSpritePreset1.hpp"

#include "Utils/Debug/DebugUtils.hpp"

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
		Tileset::Type type, 
		Tileset::Cliff cliff, 
		Orientation orient,
		Tileset::Weight weight )
{

	int tmp_id;

	if( type == Tileset::Type::Dirt ) tmp_id = 0;
	if( type == Tileset::Type::Dirt ) tmp_id = 0 + 3 * spriteHorizontalCount_;
	if( type == Tileset::Type::Dirt ) tmp_id = 0 + 6 * spriteHorizontalCount_;

	if( cliff == Tileset::Cliff::Top ) tmp_id = tmp_id + 0;
	if( cliff == Tileset::Cliff::Bottom ) tmp_id = tmp_id + 6 + spriteHorizontalCount_;
	if( cliff == Tileset::Cliff::None ) tmp_id = tmp_id + 4;
}
