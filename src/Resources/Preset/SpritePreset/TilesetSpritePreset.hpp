#ifndef TILESET_SPRITE_PRESET_HPP
#define TILESET_SPRITE_PRESET_HPP

#include <string>

#include "Utils/Debug/DebugUtils.hpp"
#include "Utils/Resources/TilesetEnum.hpp"
#include "Utils/Game/OrientationEnum.hpp"

#include "Resources/Preset/SpritePreset.hpp"


class TilesetSpritePreset : public SpritePreset
{
    public:

        virtual sf::Sprite getSprite( unsigned int frameID ) {}
	virtual sf::Sprite getSprite( 	Tileset::Type type, 
					Tileset::Cliff cliff, 
					Orientation orient, 
					Tileset::Weight weight ) {} 
};

#endif //TILESET_SPRITE_PRESET_HPP
