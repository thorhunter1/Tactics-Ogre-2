#ifndef UNIT_SPRITE_PRESET_HPP
#define UNIT_SPRITE_PRESET_HPP

#include <string>

#include "../SpritePreset.hpp"

class UnitSpritePreset : public SpritePreset
{
    public:

        virtual sf::Sprite getSprite( unsigned int frameID ) {}
};

#endif //UNIT_SPRITE_PRESET_HPP
