#ifndef SMALL_UNIT_SPRITE_PRESET_HPP
#define SMALL_UNIT_SPRITE_PRESET_HPP

#include <string>

#include "SFML.hpp"
#include "Resources/Preset/SpritePreset/UnitSpritePreset.hpp"

class SmallUnitSpritePreset2 : public UnitSpritePreset
{
    public:
	
	SmallUnitSpritePreset() {}
        virtual sf::Sprite getSprite( unsigned int frameID );

    protected:

        static const int frameWidth_    = 22;
        static const int frameHeight_   = 32;

        static const int spriteHorizontalCount_   = 11;
        static const int spriteVerticalCount_     = 4;
};

#endif //SMALL_UNIT_SPRITE_PRESET_HPP
