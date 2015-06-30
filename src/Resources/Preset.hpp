#ifndef PRESET_HPP
#define PRESET_HPP

#include <string>

#include <Utils/Debug/DebugUtils.hpp>

class Preset
{
    public:

        /// Virtual method for loading a preset resource
        virtual int load( const std::string& presetPath ) { presetPath_ = presetPath; }

	///Virtual method for loading a preset with existing path
	virtual int load() {}

        /// Virtual method for freeing a preset resource
        virtual int unload() {}

	/// Sets preset path without loading its resource
	virtual int setPresetPath( const std::string& presetPath ) { presetPath_ = presetPath; }

    protected:

	/// Last path used to load preset
	std::string presetPath_;
};

#endif //PRESET_HPP
