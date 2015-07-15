#ifndef CLIFFSET_SPRITE_PRESET_HPP
#define CLIFFSET_SPRITE_PRESET_HPP

#include <string>

#include "Utils.hh"

#include "../SpritePreset.hpp"

class CliffsetSpritePreset : public SpritePreset
{
    public:

        virtual sf::Sprite getSprite( unsigned int frameID ) {}
	    virtual sf::Sprite getSprite( 	Orientation orient, 
		       		                	Tileset::Cliff cliff, 
                                        int variation = 0 ) {} 
};

#endif //CLIFFSET_SPRITE_PRESET_HPP
