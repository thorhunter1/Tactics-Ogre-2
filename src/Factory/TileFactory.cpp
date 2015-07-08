#include "Factory/TileFactory.hpp"
#include "Resources/Preset/SpritePreset/TilesetSpritePreset/TilesetSpritePreset1.hpp"

TileFactory::TileFactory()
{
	grassPreset_ = new TilesetSpritePreset1();
	dirtPreset_ = new TilesetSpritePreset1();
	longGrassPreset_ = new TilesetSpritePreset1();
}

IsometricTile* TileFactory::create( const std::string& type )
{
    TileFactory& tf = TileFactory::getInstance();
    IsometricTile* tile = new IsometricTile();

    if( type == "grass" )       { tile->setTilePreset( tf.grassPreset_ ); tile->setTileType( "grass" ); }
    if( type == "dirt" )        { tile->setTilePreset( tf.dirtPreset_ ); tile->setTileType( "dirt" ); }
    if( type == "long_grass" )  { tile->setTilePreset( tf.longGrassPreset_ ); tile->setTileType( "long_grass" ); }

    tile->setCliff( Tileset::Cliff::None );
    tile->setWeight( Tileset::Weight::Medium );

	return tile;
}

IsometricTile* TileFactory::get( unsigned int ID )
{

}

int TileFactory::remove( unsigned int ID )
{

}

int TileFactory::remove( IsometricTile* tile )
{

}

int TileFactory::updateTileType( IsometricTile* tile, const std::string& type )
{
	TileFactory& tf = TileFactory::getInstance();
	//TODO tile->setTilePreset( tf.grassPreset_ ); 
	tile->setTileType( type );
}

int TileFactory::load()
{     
	TileFactory& tf = TileFactory::getInstance();
	tf.grassPreset_->load( "../resources/Sprites/Tileset/grass.png" );
        tf.dirtPreset_->load( "../resources/Sprites/Tileset/dirt.png" );
        tf.longGrassPreset_->load( "../resources/Sprites/Tileset/long_grass.png" );
}
