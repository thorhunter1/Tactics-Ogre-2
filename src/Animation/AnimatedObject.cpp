#include <chrono>

#include "Animation/AnimatedObject.hpp"
#include "Utils/Game/OrientationEnum.hpp"
#include "Utils/Debug/DebugUtils.hpp"
#include "Utils/Graphics/SpriteUtils.hpp"

#include "SFML.hpp"

float AnimatedObject::animationSpeedConstant_ = 0.0025;

int AnimatedObject::playAnimation( const std::string& name, bool playInLoop )
{
    currentAnimation_ = animationSet_.getAnimation( name, orientation_ );
    currentAnimation_->loop( playInLoop );

    if( !fThreadRun_ )
    {
        fThreadRun_ = true;
        animationThread_ = std::thread( &AnimatedObject::runAnimation, this );
    }

}

int AnimatedObject::stopAnimation()
{
    fThreadRun_ = false;
}

int AnimatedObject::setOrientation( Orientation orient )
{
    int ret = 0;
    orientation_ = orient;

    if( currentAnimation_ != NULL )
    {
        Animation* tmp_anim = animationSet_.getAnimation( currentAnimation_->getName(), orientation_ );
        tmp_anim->map( *currentAnimation_ );
        *currentAnimation_ = *tmp_anim;
    }
    else ret = -1;

    TraceReturn( ret, "Can't read current animation." );

}

int AnimatedObject::setAnimationSet( const AnimationSet& animationSet )
{
    animationSet_ = animationSet;
}

void AnimatedObject::runAnimation()
{
    while( fThreadRun_ )
    {
        AnimationFrame tmp_frame = currentAnimation_->popFrame();
        sf::Sprite tmp_sprite = sPreset_->getSprite( tmp_frame );
        renderSprite_ = tmp_sprite;

        if( orientation_ == Orientation::East || orientation_ == Orientation::West )
        {
            Graphics::flipX( renderSprite_ );
        }

        if( currentAnimation_->isFinished() ) break;

        using std::chrono::milliseconds;
        std::this_thread::sleep_for( 
                milliseconds( int( AnimatedObject::animationSpeedConstant_ * animationSpeed_ * 1000) ) 
        );
    }
}
