#ifndef UNIT_HPP
#define UNIT_HPP

#include "Resources/Preset/SpritePreset.hpp"
#include "Resources/Preset/AnimationSetPreset.hpp"
#include "Animation/AnimatedObject.hpp"
#include "Isometry/IsometricObject.hpp"

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
	MovementType::UnitMoveType 	movement;
	UnitSize			size;
};

class Unit : public AnimatedObject, public IsometricObject
{
	friend class UnitFactory;

    public:
	    UnitInfo info;
	    UnitStatus status;

	    /// Loads required presets
	    virtual int loadPresets();

	    /// Unloads presets while they are not required
	    virtual int unloadPresets();


    protected:

	    /// Pointer to allocated preset
	    SpritePreset* spritePreset_ = NULL;

};

#endif //UNIT_HPP
