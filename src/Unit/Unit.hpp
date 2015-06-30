#ifndef UNIT_HPP
#define UNIT_HPP

#include "Resources/Preset/SpritePreset.hpp"
#include "Animation/AnimatedObject.hpp"

#include "Utils/Game/UnitEnum.hpp"

/// Struct for general unit information
struct UnitInfo
{
	unsigned int ID;
	std::string name;
	
};

/// Struct for unit status information
struct UnitStatus
{
	UnitMoveType 	movement;
	UnitSize	size;
};

class Unit : public AnimatedObject
{
    public:
	    UnitHeader info;
	    UnitStatus status;

	    /// Loads required presets
	    virtual int loadPresets();

	    /// Unloads presets while they are not required
	    virtual int unloadPresets();


    protected:


    private:
	    /// Pointer to allocated preset
	    SpritePreset* spritePreset = NULL;

};

#endif //UNIT_HPP
