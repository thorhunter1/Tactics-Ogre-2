#include "AnimationSetPreset.hpp"

#include "Utils.hh"

int AnimationSetPreset::load( const std::string& presetPath )
{
	//dummy for now
	
	int ret = 0;

	animationSet_ = Parser::AnimationSetParser::parse( presetPath );

	if( animationSet_ == AnimationSet::None ) ret = -1;
}

AnimationSet AnimationSetPreset::getAnimationSet()
{
	return animationSet_;
}
