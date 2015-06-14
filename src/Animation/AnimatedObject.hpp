#ifndef ANIMATED_OBJECT_HPP
#define ANIMATED_OBJECT_HPP

#include <thread>
#include <mutex>

#include "Graphics/RenderableObject.hpp"
#include "Resources/Preset/SpritePreset.hpp"
#include "Animation/AnimationSet.hpp"
#include "Animation/Animation.hpp"

class AnimatedObject : public RenderableObject
{
    public:

        int     playAnimation( const std::string& name, bool playInLoop = false );
        int     stopAnimation();
        //bool    isAnimationFinished();
        int     setOrientation( Orientation orient );


    protected:

        //void onAnimationFinish();

        virtual int setSpritePreset( const SpritePreset* sPreset ) {}
        virtual int setAnimationSet( const AnimationSet& animationSet );

        SpritePreset*   sPreset_            = NULL;
        AnimationSet    animationSet_;
        Animation*      currentAnimation_   = NULL;
        float           animationSpeed_     = 100.0;
        Orientation     orientation_        = Orientation::None;

        static float    animationSpeedConstant_;

    private:

        std::thread     animationThread_;
        std::mutex      animSetMutex_;
        bool            fThreadRun_         = false;
        void runAnimation();

};

#endif // ANIMATED_OBJECT_HPPP
