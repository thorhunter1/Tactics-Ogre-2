#ifndef SMALL_UNIT_HPP
#define SMALL_UNIT_HPP

#include "Unit/Unit.hpp"
#include "Resources/Preset/SpritePreset.hpp"

class SmallUnit : public Unit
{
    public:

        SmallUnit();
        //TODO: protect this for factory use
        //virtual int setSpritePreset( const SpritePreset* sPreset );

    protected:

        //virtual int setAnimationSet( const AnimationSet& animSet );
};

#endif //SMALL_UNIT_HPP
