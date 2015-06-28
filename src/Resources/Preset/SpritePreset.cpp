#include "Resources/Preset/SpritePreset.hpp"

#include "Utils/Debug/DebugUtils.hpp"

int SpritePreset::Load( const std::string& presetPath )
{
    int ret = 0;

    if( spriteImage_ != NULL ) 
    {
        Warning( "New sprite allocated before previous one was freed" );
    }

    spriteImage_ = new sf::Image;
    ret = !spriteImage_->loadFromFile( presetPath );

    if( ret != 0 )
    {
        delete spriteImage_;
        spriteImage_ = NULL;
    }

    TraceReturn( ret, "Load from file failed" );
}

int SpritePreset::Unload()
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

sf::Image* SpritePreset::getImage()
{
    return spriteImage_;
}

