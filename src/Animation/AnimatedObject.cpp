#include <chrono>

#include "AnimatedObject.hpp"

#include "Graphics.hh"
#include "Utils.hh"
#include "Resources.hh"

#include "SFML.hpp"

float AnimatedObject::animationSpeedConstant_ = 0.0025;

int AnimatedObject::playAnimation( const std::string& name, bool playInLoop )
{
	int ret = 0;
	currentAnimation_ = animationSet_.getAnimation( name, orientation_ );

	if( currentAnimation_ == Animation::None )
	{
		ret = -1;
		TraceReturn( ret, "Can't play Animation::None" );
	}
	currentAnimation_.loop( playInLoop );

	if( !fThreadRun_ )
	{
		fThreadRun_ = true;
		animationThread_ = std::thread( &AnimatedObject::_runAnimation, this );
		animationThread_.detach();
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

	if( currentAnimation_ != Animation::None ) //currentAnimation_.getName() != "none" )
	{
		Animation tmp_anim = animationSet_.getAnimation( currentAnimation_.getName(), orientation_ );
		tmp_anim.map( currentAnimation_ );
		currentAnimation_ = tmp_anim;
	}
	else ret = -1;

	TraceReturn( ret, "Can't read current animation." );

}

int AnimatedObject::rotate()
{
	if( orientation_ == Orientation::None ) return -1;
	if( orientation_ == Orientation::North ) { setOrientation( Orientation::East ); return 0; }
	if( orientation_ == Orientation::East ) { setOrientation( Orientation::South ); return 0; }
	if( orientation_ == Orientation::South ) { setOrientation( Orientation::West ); return 0; }
	if( orientation_ == Orientation::West ) { setOrientation( Orientation::North ); return 0; }
}

int AnimatedObject::setAnimationSpeed( float speed )
{
	animationSpeed_ = speed;
}

int AnimatedObject::bindSpritePreset( SpritePreset* sPreset )
{
	int ret = 0;

	if( sPreset != NULL )
		sPreset_ = sPreset;
	else
		ret = -1;

	TraceReturn( ret, "Cannot bind a null pointer" );
}

int AnimatedObject::unbindSpritePreset()
{
	sPreset_ = NULL;
}

int AnimatedObject::setAnimationSet( const AnimationSet& animationSet )
{
	animationSet_ = animationSet;
}

void AnimatedObject::_runAnimation()
{
	while( fThreadRun_ )
	{
		AnimationFrame tmp_frame = currentAnimation_.popFrame();

		sf::Sprite tmp_sprite = sPreset_->getSprite( tmp_frame );

		if( orientation_ == Orientation::East || orientation_ == Orientation::West )
		{
			Graphics::flipX( tmp_sprite );
		}

		setRenderSprite( tmp_sprite );

		if( currentAnimation_.isFinished() ) break;

		using std::chrono::milliseconds;
		std::this_thread::sleep_for( 
				milliseconds( int( AnimatedObject::animationSpeedConstant_ * animationSpeed_ * 1000 ) ) 
				);
	}
	stopAnimation();
	//animationThread_.join();
}
