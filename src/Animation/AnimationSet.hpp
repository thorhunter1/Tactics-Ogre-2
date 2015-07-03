#ifndef ANIMATION_SET_HPP
#define ANIMATION_SET_HPP

#include <map>

#include "Animation/Animation.hpp"
#include "Utils/Game/OrientationEnum.hpp"

class AnimationSet
{
    public:

        static const AnimationSet None;

    public:

        AnimationSet() {}

	/// Gets animation from available set. Returns Animation::None if not found.
        Animation getAnimation( const std::string& name, Orientation orientation );

	/// Adds animation to available set
        int addAnimation( const Animation& animation, Orientation orientation );

    protected:

        std::map< std::string, std::map<Orientation, Animation> > animationSet_;

    public:

        bool operator ==( const AnimationSet& other ) const;
        bool operator !=( const AnimationSet& other ) const;
};

#endif //ANIMATION_SET_HPP
