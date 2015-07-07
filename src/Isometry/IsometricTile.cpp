#include "Isometry/IsometricTile.hpp"

IsometricTile::IsometricTile()
{
    rendObjects_[Orientation::North] = RenderableObject();
    rendObjects_[Orientation::South] = RenderableObject();
    rendObjects_[Orientation::West] = RenderableObject();
    rendObjects_[Orientation::East] = RenderableObject();
}

int IsometricTile::setTilePreset( TilesetSpritePreset* preset )
{
	tilePreset_ = preset;
	//tilePreset_->load();

	auto iter = rendObjects_.begin();

	while( iter != rendObjects_.end() )
	{
		RenderableObject& rend_obj = iter->second;
        Debug( preset->getImage()->getSize().x );
		rend_obj.bindRenderImage( *preset->getImage() );
		rend_obj.updateTexture();

		++iter;
	}
}

int IsometricTile::setTileType( const std::string& type )
{
	tileType_ = type;
}

sf::Sprite IsometricTile::getRenderTileSprite( Orientation orient )
{
	return rendObjects_[orient].getRenderSprite();
}

const std::string& IsometricTile::getTileType()
{
	return tileType_;
}

Tileset::Weight IsometricTile::getWeight( Orientation orient )
{
	return tileInfo_[orient].weight;
}

Tileset::Cliff IsometricTile::getCliff( Orientation orient )
{
	return tileInfo_[orient].cliff;
}

Tileset::CliffType IsometricTile::getCliffType( Orientation orient )
{
	return tileInfo_[orient].cliff_type;
}

int IsometricTile::setCliff( Tileset::Cliff cliff, Orientation orient )
{
	tileInfo_[orient].cliff = cliff;
	_updateSprite( orient );
}

int IsometricTile::setCliff( Tileset::Cliff cliff )
{
	setCliff( cliff, Orientation::North );
	setCliff( cliff, Orientation::South );
	setCliff( cliff, Orientation::West );
	setCliff( cliff, Orientation::East );
}

int IsometricTile::setCliffType( Tileset::CliffType cliffType, Orientation orient )
{
	tileInfo_[orient].cliff_type = cliffType;
	_updateSprite( orient );
}

int IsometricTile::setCliffType( Tileset::CliffType cliffType )
{
	setCliffType( cliffType, Orientation::North );
	setCliffType( cliffType, Orientation::South );
	setCliffType( cliffType, Orientation::West );
	setCliffType( cliffType, Orientation::East );
}

int IsometricTile::setWeight( Tileset::Weight weight, Orientation orient )
{
	tileInfo_[orient].weight = weight;
	_updateSprite( orient );
}

int IsometricTile::setWeight( Tileset::Weight weight )
{
	setWeight( weight, Orientation::North );
	setWeight( weight, Orientation::South );
	setWeight( weight, Orientation::West );
	setWeight( weight, Orientation::East );
}

int IsometricTile::_updateSprite( Orientation orient )
{
	Tileset::TileInfo info = tileInfo_[orient];
	sf::Sprite tmp_sprite = tilePreset_->getSprite( info.cliff, orient, info.weight, info.cliff_type );
	rendObjects_[orient].setRenderSprite( tmp_sprite );
}


