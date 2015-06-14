#include "Resources/Preset/SpritePreset.hpp"

#include "Utils/Debug/DebugUtils.hpp"

int SpritePreset::Load( const std::string& presetPath )
{
    int ret = !spriteImage_.loadFromFile( presetPath );

    TraceReturn( ret, "Load from file failed" );
}

