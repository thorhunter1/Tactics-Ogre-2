#include "Graphics/Renderer.hpp"
#include "Utils/Graphics/ImageUtils.hpp"
#include "Utils/Debug/DebugUtils.hpp"

#include "SFML.hpp"

#include "Resources/Preset/SpritePreset/TilesetSpritePreset/TilesetSpritePreset1.hpp"

sf::RenderWindow Renderer::window_;

int Renderer::init()
{
    window_.create( sf::VideoMode( 800, 600 ), "My window", sf::Style::Close );
}

int Renderer::render( RenderableObject* obj, int x, int y )
{
    if( obj->fUpdateTexture_ )
    {
        sf::Image image = obj->renderImage_;
        Graphics::teamColor( image, obj->teamColor_ );
        obj->updateTexture( image );
    }

    sf::Sprite sprite = obj->getRenderSprite();
    sprite.setPosition( x, y );
    sprite.setScale( 2, 2 );

    window_.draw( sprite );

    return 0;
}

int Renderer::render( IsometricTile* tile, int x, int y )
{
	const int offset = 16;

    sf::Sprite sprite1 = tile->getRenderTileSprite( Orientation::North );
    sf::Sprite sprite2 = tile->getRenderTileSprite( Orientation::South );
    sf::Sprite sprite3 = tile->getRenderTileSprite( Orientation::West );
    sf::Sprite sprite4 = tile->getRenderTileSprite( Orientation::East );

	sprite1.setPosition( x - 2 * offset, y - offset );
	sprite1.setScale( 2, 2 );

	sprite2.setPosition( x, y );
	sprite2.setScale( 2, 2 );

	sprite3.setPosition( x - 2 * offset, y );
	sprite3.setScale( 2, 2 );

	sprite4.setPosition( x, y - offset );
	sprite4.setScale( 2, 2 );

	window_.draw( sprite1 );
	window_.draw( sprite2 );
	window_.draw( sprite3 );
	window_.draw( sprite4 );
}

/*
int Renderer::render_tile()
{

	static TilesetSpritePreset* preset = new TilesetSpritePreset1();
	static int once = 1;

	if( once == 1 )
	{
		once = 0;
		preset->load( "../resources/Sprites/Tileset/long_grass.png" );
	}

	IsometricTile tile;
	tile.setTilePreset( preset );
	tile.setCliff( Tileset::Cliff::Top );
    tile.setCliffType( Tileset::CliffType::Rugged );
	tile.setWeight( Tileset::Weight::Medium );
    
    sf::Sprite sprite1 = tile.getRenderTileSprite( Orientation::North );
    sf::Sprite sprite2 = tile.getRenderTileSprite( Orientation::South );
    sf::Sprite sprite3 = tile.getRenderTileSprite( Orientation::West );
    sf::Sprite sprite4 = tile.getRenderTileSprite( Orientation::East );

	sprite1.setPosition( 50, 50 );
	sprite1.setScale( 2, 2 );

	sprite2.setPosition( 50 + 2*offset, 50 + offset );
	sprite2.setScale( 2, 2 )
		;
	sprite3.setPosition( 50, 50 + offset );
	sprite3.setScale( 2, 2 );

	sprite4.setPosition( 50 + 2*offset, 50 );
	sprite4.setScale( 2, 2 );
	
	window_.draw( sprite1 );
	window_.draw( sprite2 );
	window_.draw( sprite3 );
	window_.draw( sprite4 );
}
*/

int Renderer::d_render( RenderableObject* obj, int x, int y )
{
	sf::Sprite sprite = obj->d_getTextureSprite();
	sprite.setPosition( x, y );
	sprite.setScale( 2, 2 );

	window_.draw( sprite );
}

int Renderer::clear()
{
    window_.display();
    window_.clear();
}

