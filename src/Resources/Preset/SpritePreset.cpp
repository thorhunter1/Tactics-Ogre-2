#include "SpritePreset.hpp"

#include "Utils.hh"

int SpritePreset::load()
{
	load( getPresetPath() );
}

int SpritePreset::load( const std::string& presetPath )
{
    int ret = 0;

    if( spriteImage_ != NULL ) 
    {
        Warning( "New sprite allocated before previous one was freed" );
	unload();
    }

    spriteImage_ = new sf::Image;
    ret = !spriteImage_->loadFromFile( presetPath );

    setPresetPath( presetPath );

    if( ret != 0 )
    {
        delete spriteImage_;
        spriteImage_ = NULL;
    }

    TraceReturn( ret, "Load from file failed" );
}

int SpritePreset::unload()
{
    int ret = 0;

    if( spriteImage_ != NULL )
    {
        delete spriteImage_;
        spriteImage_ = NULL;
    }
    else ret = -1;

    TraceReturn( ret, "Unload of spriteImage_ failed" );
}

sf::Sprite SpritePreset::getSprite()
{

	sf::Sprite tmp_sprite = sf::Sprite();
	if( spriteImage_ == NULL )
	{
		Warning( "No image loaded" );
		return tmp_sprite;
	}

	sf::IntRect tmp_rect = sf::IntRect( 0, 0, spriteImage_->getSize().x, spriteImage_->getSize().y );
	tmp_sprite.setTextureRect( tmp_rect );

	return tmp_sprite;

}

sf::Image* SpritePreset::getImage()
{
    return spriteImage_;
}

