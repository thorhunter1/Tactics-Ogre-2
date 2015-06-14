#include "Animation/AnimationSet.hpp"

#include "Utils/Debug/DebugUtils.hpp"

Animation* AnimationSet::getAnimation( const std::string& name, Orientation orientation )
{
    if(     animationSet_.find( name )              != animationSet_.end() &&
            animationSet_[name].find( orientation ) != animationSet_[name].end() )
    {
        return &animationSet_[name][orientation];
    }
    else
    {
        Error( "Couldn't find animation: " << name );

        return NULL;
    }

}

int AnimationSet::addAnimation( const Animation& animation, Orientation orientation )
{
    animationSet_[animation.getName()][orientation] = animation;
}
