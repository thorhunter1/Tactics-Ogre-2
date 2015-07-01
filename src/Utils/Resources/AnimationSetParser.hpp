#ifndef ANIMATION_SET_PARSER_HPP
#define ANIMATION_SET_PARSER_HPP

#include "Animation/AnimationSet.hpp"

namespace Parser
{

class AnimationSetParser
{
	public:
		static AnimationSet parse( const std::string& path );

	private:
		AnimationSetParser& getInstance() { static AnimationSetParser p; return p; }
};

};


#endif //ANIMATION_SET_PARSER_HPP
