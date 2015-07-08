#ifndef ANIMATION_SET_PRESET_HPP
#define ANIMATION_SET_PRESET_HPP

#include <string>

#include "SFML.hpp"

#include "Animation.hh"

class Preset;

class AnimationSetPreset : public Preset
{
    protected:

        // TODO: perhaps make it allocable pointer?
        /// AnimationSet handle
        AnimationSet  animationSet_ = AnimationSet::None;

    public:
    
        /// Loads AnimationSet from file into memory
        virtual int load( const std::string& presetPath );

        /// Frees loaded AnimationSet
        //virtual int unload();

        /// Returns AnimationSet
        virtual AnimationSet getAnimationSet();
};

#endif //ANIMATION_SET_PRESET_HPP
