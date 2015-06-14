#ifndef UNIT_SPRITE_PRESET_HPP
#define UNIT_SPRITE_PRESET_HPP

#include <string>

#include "Utils/Debug/DebugUtils.hpp"

#include "Resources/Preset/SpritePreset.hpp"

class UnitSpritePreset : public SpritePreset
{
    public:

        virtual int Load( const std::string& presetPath ) {}
        
        virtual sf::Sprite getSprite() {}
        virtual sf::Sprite getSprite( unsigned int frameID ) {}
};

#endif //UNIT_SPRITE_PRESET_HPP
