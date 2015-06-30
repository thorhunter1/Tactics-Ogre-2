#ifndef SMALL_UNIT_SPRITE_PRESET_HPP
#define SMALL_UNIT_SPRITE_PRESET_HPP

#include <string>

#include "SFML.hpp"
#include "Resources/Preset/SpritePreset/UnitSpritePreset.hpp"

class SmallUnitSpritePreset : public UnitSpritePreset
{
    public:
	
	SmallUnitSpritePreset() {}
        virtual sf::Sprite getSprite( unsigned int frameID );

    protected:

        static const int frameWidth_    = 16;
        static const int frameHeight_   = 32;

        static const int spriteHorizontalCount_   = 9;
        static const int spriteVerticalCount_     = 2;
};

#endif //SMALL_UNIT_SPRITE_PRESET_HPP
