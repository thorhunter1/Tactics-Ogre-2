#ifndef PRESET_HPP
#define PRESET_HPP

#include <string>

#include <Utils/Debug/DebugUtils.hpp>

class Preset
{
    public:

        virtual int Load( const std::string& presetPath ) {}
};

#endif //PRESET_HPP
