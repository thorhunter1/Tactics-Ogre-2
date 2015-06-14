#ifndef SPRITE_PRESET_HPP
#define SPRITE_PRESET_HPP

#include <string>

#include "SFML.hpp"
#include "Utils/Debug/DebugUtils.hpp"

#include "Resources/Preset.hpp"

class SpritePreset : public Preset
{
    protected:

        sf::Image  spriteImage_;

    public:

        virtual int Load( const std::string& presetPath );
        virtual sf::Sprite getSprite( unsigned int frameID ) {}

        sf::Image& getImage() { return spriteImage_; }

};

#endif //SPRITE_PRESET_HPP
