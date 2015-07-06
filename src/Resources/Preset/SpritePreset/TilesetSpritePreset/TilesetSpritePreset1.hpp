#ifndef TILESET1_SPRITE_PRESET_HPP
#define TILESET1_SPRITE_PRESET_HPP

#include <string>

#include "SFML.hpp"
#include "Resources/Preset/SpritePreset/TilesetSpritePreset.hpp"

class TilesetSpritePreset1 : public TilesetSpritePreset
{
    public:
	
	TilesetSpritePreset1() {}
        virtual sf::Sprite getSprite( unsigned int frameID );
	virtual sf::Sprite getSprite( 	Tileset::Type type,
					Tileset::Cliff cliff,
					Orientation orient,
					Tileset::Weight weight );

    protected:

        static const int frameWidth_    = 16;
        static const int frameHeight_   = 8;

        static const int spriteHorizontalCount_   = 12;
        static const int spriteVerticalCount_     = 11;
};

#endif //TILESET1_SPRITE_PRESET_HPP
