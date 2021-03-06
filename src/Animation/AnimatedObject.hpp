#ifndef ANIMATED_OBJECT_HPP
#define ANIMATED_OBJECT_HPP

#include <thread>
#include <mutex>

#include "Animation/AnimationSet.hpp"
#include "Animation/Animation.hpp"

#include "Graphics.hh"

class SpritePreset;

class AnimatedObject : public virtual RenderableObject
{
	//TODO: get rid of this
	friend class UnitFactory;

    public:

        /// plays animation
        int     playAnimation( const std::string& name, bool playInLoop = false );

        /// stops playing animation
        int     stopAnimation();

        /// checks if animation finished playing
        bool    isAnimationFinished();

        /// sets orientation of this object
        int     setOrientation( Orientation orient );

        /// rotates this object clockwise
        int     rotate();

        /// sets animation speed % of this object
        int     setAnimationSpeed( float speed );

    protected:

        /// binds handle of sprite preset to this object
        virtual int bindSpritePreset( SpritePreset* sPreset );

	/// unbinds handle of sprite preset from this object
	virtual int unbindSpritePreset();

        /// sets animation set of this object
        virtual int setAnimationSet( const AnimationSet& animationSet );

        SpritePreset*   sPreset_            = NULL;
        AnimationSet    animationSet_       = AnimationSet::None;
        Animation       currentAnimation_   = Animation::None;
        float           animationSpeed_     = 100.0;
        Orientation     orientation_        = Orientation::None;

        static float    animationSpeedConstant_;

    private:

        /// External thread managing the animation
        void            _runAnimation();
        
        std::thread     animationThread_;
        std::mutex      animSetMutex_;
        bool            fThreadRun_         = false;

};

#endif // ANIMATED_OBJECT_HPPP
