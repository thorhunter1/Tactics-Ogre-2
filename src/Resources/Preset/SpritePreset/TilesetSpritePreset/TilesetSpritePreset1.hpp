#ifndef TILESET1_SPRITE_PRESET_HPP
#define TILESET1_SPRITE_PRESET_HPP

#include <string>

#include "SFML.hpp"
#include "../TilesetSpritePreset.hpp"

#include "Utils.hh"

class TilesetSpritePreset1 : public TilesetSpritePreset
{
    public:
	
	TilesetSpritePreset1() {}
        virtual sf::Sprite getSprite( unsigned int frameID );
	virtual sf::Sprite getSprite(	Tileset::Cliff cliff,
					Orientation orient,
					Tileset::Weight weight,
		       			Tileset::CliffType cliffType = Tileset::CliffType::Smooth );

    protected:

        static const int frameWidth_    = 16;
        static const int frameHeight_   = 8;

        static const int spriteHorizontalCount_   = 10;
        static const int spriteVerticalCount_     = 2;
};

#endif //TILESET1_SPRITE_PRESET_HPP
