#include "IsometricTile.hpp"
#include "Graphics.hh"
#include "Isometry.hh"
#include "Resources.hh"

IsometricTile::IsometricTile()
{
    rendTileObjects_[Orientation::North] = RenderableObject();
    rendTileObjects_[Orientation::South] = RenderableObject();
    rendTileObjects_[Orientation::West] = RenderableObject();
    rendTileObjects_[Orientation::East] = RenderableObject();

    rendCliffObjects_[Orientation::North] = RenderableObject();
    rendCliffObjects_[Orientation::South] = RenderableObject();
    rendCliffObjects_[Orientation::West] = RenderableObject();
    rendCliffObjects_[Orientation::East] = RenderableObject();

}

int IsometricTile::setTilePreset( TilesetSpritePreset* preset )
{
	tilePreset_ = preset;

    //TODO: Loading preset should be handled externally 
	//int ret = tilePreset_->load();
    //if( ret !=0 ) TraceReturn( ret, "Couldn't reload tile" );

	auto iter = rendTileObjects_.begin();

	while( iter != rendTileObjects_.end() )
	{
		RenderableObject& rend_obj = iter->second;
		rend_obj.bindRenderImage( *preset->getImage() );
		rend_obj.updateTexture();

		++iter;
	}
}

int IsometricTile::setCliffPreset( CliffsetSpritePreset* preset )
{
	cliffPreset_ = preset;

    //TODO: Loading preset should be handled externally 
	//int ret = tilePreset_->load();
    //if( ret !=0 ) TraceReturn( ret, "Couldn't reload tile" );

	auto iter = rendCliffObjects_.begin();

	while( iter != rendCliffObjects_.end() )
	{
		RenderableObject& rend_obj = iter->second;
		rend_obj.bindRenderImage( *preset->getImage() );
		rend_obj.updateTexture();

		++iter;
	}
}

int IsometricTile::setTileType( const std::string& type )
{
	tileType_ = type;
}

int IsometricTile::setCliffType( const std::string& type )
{
    cliffType_ = type;
}

sf::Sprite IsometricTile::getRenderTileSprite( Orientation orient )
{
	return rendTileObjects_[orient].getRenderSprite();
}

sf::Sprite IsometricTile::getRenderCliffSprite( Orientation orient )
{
	return rendCliffObjects_[orient].getRenderSprite();
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

int IsometricTile::setLayer( int layer )
{
	layer_ = layer;
}

int IsometricTile::getLayer()
{
	return layer_;
}

int IsometricTile::_updateSprite()
{
	_updateSprite( Orientation::North );
	_updateSprite( Orientation::South );
	_updateSprite( Orientation::West );
	_updateSprite( Orientation::East );
}

int IsometricTile::_updateSprite( Orientation orient )
{
	Tileset::TileInfo info = tileInfo_[orient];
	sf::Sprite tmp_sprite = tilePreset_->getSprite( info.cliff, orient, info.weight, info.cliff_type );
	rendTileObjects_[orient].setRenderSprite( tmp_sprite );

    sf::Sprite tmp_sprite2 = cliffPreset_->getSprite( orient, info.cliff );
    rendCliffObjects_[orient].setRenderSprite( tmp_sprite2 );
}


