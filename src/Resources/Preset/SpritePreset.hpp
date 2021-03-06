#ifndef SPRITE_PRESET_HPP
#define SPRITE_PRESET_HPP

#include <string>

#include "SFML.hpp"
#include "Utils.hh"

#include "../Preset.hpp"

class SpritePreset : public Preset
{
    protected:

        /// Image handle representing sprite preset
        sf::Image*  spriteImage_ = NULL;

    public:
 
        /// Loads image from file into memory
        virtual int load( const std::string& presetPath );

	/// Loads image from preset path into mempry
	virtual int load();

        /// Frees loaded image
        virtual int unload();

        /*! Returns sprite based on frame ID specified
         * @image html SpriteID.png
         */
        virtual sf::Sprite getSprite( unsigned int frameID ) {}

	///Returns sprite of whole trxture
	virtual sf::Sprite getSprite();

        /// Returns handle to image resource
        sf::Image* getImage();

};

#endif //SPRITE_PRESET_HPP
