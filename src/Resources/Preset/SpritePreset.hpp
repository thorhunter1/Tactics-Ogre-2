#ifndef SPRITE_PRESET_HPP
#define SPRITE_PRESET_HPP

#include <string>

#include "SFML.hpp"
#include "Utils/Debug/DebugUtils.hpp"

#include "Resources/Preset.hpp"

class SpritePreset : public Preset
{
    protected:

        /// Image handle representing sprite preset
        sf::Image*  spriteImage_ = NULL;

    public:
    
        /// Loads image from file into memory
        virtual int Load( const std::string& presetPath );

        /// Frees loaded image
        virtual int Unload();

        /*! Returns sprite based on frame ID specified
         * @image html SpriteID.png
         */
        virtual sf::Sprite getSprite( unsigned int frameID ) {}

        /// Returns handle to image resource
        sf::Image* getImage();

};

#endif //SPRITE_PRESET_HPP
