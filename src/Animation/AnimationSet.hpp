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
        Animation& getAnimation( const std::string& name, Orientation orientation );
        int addAnimation( const Animation& animation, Orientation orientation );

    protected:

        std::map< std::string, std::map<Orientation, Animation> > animationSet_;

    public:

        bool operator ==( const AnimationSet& other );
        bool operator !=( const AnimationSet& other );
};

#endif //ANIMATION_SET_HPP
