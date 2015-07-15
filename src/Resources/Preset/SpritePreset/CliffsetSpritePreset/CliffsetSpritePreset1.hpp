#ifndef CLIFFSET_SPRITE_PRESET1_HPP
#define CLIFFSET_SPRITE_PRESET1_HPP

#include <string>

#include "SFML.hpp"
#include "../CliffsetSpritePreset.hpp"

#include "Utils.hh"

class CliffsetSpritePreset1 : public CliffsetSpritePreset
{
    public:
	
	CliffsetSpritePreset1() {}
    virtual sf::Sprite getSprite( unsigned int frameID );
	virtual sf::Sprite getSprite(	Orientation orient,
		       			            Tileset::Cliff cliff,
                                    int variation = 0 );

    protected:

        static const int frameWidth_        = 16;
        static const int frameHeight_       = 16;

        static const int spriteHorizontalCount_   = 2;
        static const int spriteVerticalCount_     = 4;
};

#endif //TILESET1_SPRITE_PRESET_HPP
