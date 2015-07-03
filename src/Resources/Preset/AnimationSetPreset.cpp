#include "Resources/Preset/AnimationSetPreset.hpp"

#include "Utils/Resources/AnimationSetParser.hpp"

int AnimationSetPreset::load( const std::string& presetPath )
{
	//dummy for now
	
	int ret = 0;

	animationSet_ = Parser::AnimationSetParser::parse( presetPath );

	if( animationSet_ == AnimationSet::None ) ret = -1;

	TraceReturn( ret, "Couldn't load preset" );
	
	Animation walk_S    = Animation( "walk",    {0,1,0,2}       );
	Animation stand_S   = Animation( "stand",   {0}             );
	Animation run_S     = Animation( "run",     {1,2}           );
	Animation attack_S  = Animation( "attack",  {0,6,7,8,6,0}   );

	Animation walk_N    = Animation( "walk",    {3,4,3,5}           );
	Animation stand_N   = Animation( "stand",   {3}                 );
	Animation run_N     = Animation( "run",     {4,5}               );
	Animation attack_N  = Animation( "attack",  {3,15,16,17,15,3}   );

	animationSet_.addAnimation( walk_N,     Orientation::North );
	animationSet_.addAnimation( stand_N,    Orientation::North );
	animationSet_.addAnimation( run_N,      Orientation::North );
	animationSet_.addAnimation( attack_N,   Orientation::North );

	animationSet_.addAnimation( walk_S,     Orientation::South );
	animationSet_.addAnimation( stand_S,    Orientation::South );
	animationSet_.addAnimation( run_S,      Orientation::South );
	animationSet_.addAnimation( attack_S,   Orientation::South );

	animationSet_.addAnimation( walk_N,     Orientation::East );
	animationSet_.addAnimation( stand_N,    Orientation::East );
	animationSet_.addAnimation( run_N,      Orientation::East );
	animationSet_.addAnimation( attack_N,   Orientation::East );

	animationSet_.addAnimation( walk_S,     Orientation::West );
	animationSet_.addAnimation( stand_S,    Orientation::West );
	animationSet_.addAnimation( run_S,      Orientation::West );
	animationSet_.addAnimation( attack_S,   Orientation::West );

}

AnimationSet AnimationSetPreset::getAnimationSet()
{
	return animationSet_;
}
