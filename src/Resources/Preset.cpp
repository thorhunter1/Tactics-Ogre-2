#include "Preset.hpp"

int Preset::setPresetPath( const std::string& presetPath )
{
	presetPath_ = presetPath;
}

std::string Preset::getPresetPath()
{
	return presetPath_;
}
