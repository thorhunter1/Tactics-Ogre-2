#ifndef ANIMATION_SET_HPP
#define ANIMATION_SET_HPP

#include <map>

#include "Animation/Animation.hpp"
#include "Utils/Game/OrientationEnum.hpp"

class AnimationSet
{
    public:

        AnimationSet() {}
        Animation& getAnimation( const std::string& name, Orientation orientation );
        int addAnimation( const Animation& animation, Orientation orientation );

    protected:

        std::map< std::string, std::map<Orientation, Animation> > animationSet_;
};

#endif //ANIMATION_SET_HPP
