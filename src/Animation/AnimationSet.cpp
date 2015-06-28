#include "Animation/AnimationSet.hpp"

#include "Utils/Debug/DebugUtils.hpp"

Animation& AnimationSet::getAnimation( const std::string& name, Orientation orientation )
{
    if(     animationSet_.find( name )              != animationSet_.end() &&
            animationSet_[name].find( orientation ) != animationSet_[name].end() )
    {
        return animationSet_[name][orientation];
    }
    else
    {
        Error( "Couldn't find animation: " << name );

        Animation empty_animation = Animation::None;
        return empty_animation;
    }

}

int AnimationSet::addAnimation( const Animation& animation, Orientation orientation )
{
    animationSet_[animation.getName()][orientation] = animation;
}

bool AnimationSet::operator ==( const AnimationSet& other )
{
    return true;
    //return animationSet_ == other.animationSet_;
}

bool AnimationSet::operator !=( const AnimationSet& other )
{
    return true;
    //return animationSet_ != other.animationSet_;
}
