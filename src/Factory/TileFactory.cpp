#include "TileFactory.hpp"

#include "Resources.hh"

TileFactory::TileFactory()
{
	grassPreset_ = new TilesetSpritePreset1();
	dirtPreset_ = new TilesetSpritePreset1();
	longGrassPreset_ = new TilesetSpritePreset1();

	dummyCliffPreset_ = new CliffsetSpritePreset1();
}

IsometricTile* TileFactory::create( const std::string& type, int x, int y, int z )
{
	TileFactory& tf = TileFactory::getInstance();
	IsometricTile* tile = new IsometricTile();

	if( type == "grass" )       
	{ 
		tile->setTilePreset( tf.grassPreset_ ); 
		tile->setTileType( "grass" ); 
		tile->setLayer(1);
	}
	if( type == "dirt" )        
	{ 
		tile->setTilePreset( tf.dirtPreset_ ); 
		tile->setTileType( "dirt" ); 
		tile->setLayer(0);
	}
	if( type == "long_grass" )  
	{ 
		tile->setTilePreset( tf.longGrassPreset_ ); 
		tile->setTileType( "long_grass" ); 
		tile->setLayer(2);
	}

	tile->setCliffPreset( tf.dummyCliffPreset_ );

	tile->setCliff( Tileset::Cliff::Top );
	tile->setCliffType( Tileset::CliffType::Rugged );
	tile->setWeight( Tileset::Weight::Medium );

	tile->setPosition( x, y, z );

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

	tf.dummyCliffPreset_->load( "../resources/Sprites/Cliffset/dummy_cliff.png" );
}
