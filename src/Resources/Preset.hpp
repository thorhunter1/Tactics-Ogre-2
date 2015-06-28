#ifndef PRESET_HPP
#define PRESET_HPP

#include <string>

#include <Utils/Debug/DebugUtils.hpp>

class Preset
{
    public:

        /// Virtual method for loading a preset resource
        virtual int Load( const std::string& presetPath ) {}

        /// Virtual method for freeing a preset resource
        virtual int Unload() {}
};

#endif //PRESET_HPP
