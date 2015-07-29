#ifndef ISOMETRIC_TILE_HPP
#define ISOMETRIC_TILE_HPP

#include "IsometricObject.hpp"
#include "Utils.hh"

class TilesetSpritePreset;
class CliffsetSpritePreset;
class RenderableObject;

class IsometricTile : public IsometricObject
{
	public:

        IsometricTile();

		int setTilePreset( TilesetSpritePreset* preset );
		int setCliffPreset( CliffsetSpritePreset* preset );

		int setTileType( const std::string& type );
 	       int setCliffType( const std::string& type );

		sf::Sprite getRenderTileSprite( Orientation orient );
        sf::Sprite getRenderCliffSprite( Orientation orient );

		/// Gets type of the tile, eg "grass"
		const std::string& getTileType();
        const std::string& getCliffType();

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

		/// Sets layer of tile
		int setLayer( int layer );
		int getLayer();

	protected:

		std::string tileType_;
        	std::string cliffType_;

		std::map< Orientation, RenderableObject > rendTileObjects_;
		std::map< Orientation, RenderableObject > rendCliffObjects_;

		std::map< Orientation, Tileset::TileInfo > tileInfo_;

		TilesetSpritePreset* 	tilePreset_;
		CliffsetSpritePreset*   cliffPreset_;
		int			layer_;
		
		int _updateSprite();
		int _updateSprite( Orientation orient );
};

#endif //ISOMETRIC_TILE_HPP
