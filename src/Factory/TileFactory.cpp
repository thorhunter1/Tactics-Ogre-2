#include "Factory/TileFactory.hpp"
#include "Resources/Preset/SpritePreset/TilesetSpritePreset/TilesetSpritePreset1.hpp"

IsometricTile* TileFactory::create( const std::string& type )
{
    static TilesetSpritePreset* grass_preset = new TilesetSpritePreset1();
    static TilesetSpritePreset* dirt_preset = new TilesetSpritePreset1();
    static TilesetSpritePreset* long_grass_preset = new TilesetSpritePreset1();

    static int once = 1;
    if( once )
    {
        once = 0;
        grass_preset->load( "../resources/Sprites/Tileset/grass.png" );
        dirt_preset->load( "../resources/Sprites/Tileset/dirt.png" );
        long_grass_preset->load( "../resources/Sprites/Tileset/long_grass.png" );
    }

    IsometricTile* tile = new IsometricTile();

    if( type == "grass" )       tile->setTilePreset( grass_preset );
    if( type == "dirt" )        tile->setTilePreset( dirt_preset );
    if( type == "long_grass" )  tile->setTilePreset( long_grass_preset );

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
