#ifndef TILESET_SPRITE_PRESET_HPP
#define TILESET_SPRITE_PRESET_HPP

#include <string>

#include "Utils.hh"

#include "../SpritePreset.hpp"

class TilesetSpritePreset : public SpritePreset
{
    public:

        virtual sf::Sprite getSprite( unsigned int frameID ) {}
	virtual sf::Sprite getSprite(	Tileset::Cliff cliff, 
					Orientation orient, 
					Tileset::Weight weight,
		       			Tileset::CliffType cliffType = Tileset::CliffType::Smooth ) {} 
};

#endif //TILESET_SPRITE_PRESET_HPP
