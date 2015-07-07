#ifndef ISOMETRIC_TILE_HPP
#define ISOMETRIC_TILE_HPP

#include "Isometry/IsometricObject.hpp"
#include "Animation/AnimatedObject.hpp"

#include "Resources/Preset/SpritePreset/TilesetSpritePreset.hpp"
#include "Utils/Resources/TilesetEnum.hpp"

class IsometricTile : public IsometricObject
{
	public:
		int setTilePreset( TilesetSpritePreset* preset );
		int setCliffPreset( /*const CliffSpritePreset& preset*/ ) {}

		int setTileType( const std::string& type );

		sf::Sprite getRenderTileSprite( Orientation orient );

		/// Gets type of the tile, eg "grass"
		const std::string& getTileType();

		/// Gets weight of tile on given orientation
		Tileset::Weight getWeight( Orientation orient );

		/// Gets information about cliff
		Tileset::Cliff getCliff( Orientation orient );

		/// Gets cliff type
		Tileset::CliffType getCliffType( Orientation orient );

		/// Sets cliff
		int setCliff( Tileset::Cliff cliff, Orientation orient );
		int setCliff( Tileset::Cliff cliff );

		/// Sets cliff type of the tile
		int setCliffType( Tileset::CliffType cliffType, Orientation orient );
		int setCliffType( Tileset::CliffType cliffType );

		/// Sets weight of tile on given orientation
		int setWeight( Tileset::Weight weight, Orientation orient );

		/// Sets weight of tile on all orientations
		int setWeight( Tileset::Weight weight );

	protected:

		std::string tileType_;
		std::map< Orientation, RenderableObject > rendObjects_;
		std::map< Orientation, Tileset::TileInfo > tileInfo_;

		TilesetSpritePreset* 	tilePreset_;
		//CliffSpritePreset*	cliffPreset_;
		
		int _updateSprite( Orientation orient );
		




};

#endif //ISOMETRIC_TILE_HPP
