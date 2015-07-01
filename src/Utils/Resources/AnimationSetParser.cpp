#include "json/json.h"

#include "Utils/Resources/AnimationSetParser.hpp"

namespace Parser
{

	AnimationSet AnimationSetParser::parse( const std::string& path )
	{
		AnimationSet set = AnimationSet::None;

		Json::Value root;
		Json::Reader reader;

		reader.parse( path, root );

		Json::Value animation_set = root["animation_set"];

		// Parse through all animations
		Json::Value::iterator iter = animation_set.begin();

		while( iter != animation_set.end() )
		{
			Json::Value anim = (*iter);
			std::string name = anim["name"].asString();

			//Parse through south frames
			AnimationFrameList frame_list;
			Json::Value south = anim["south"];
			Json::Value::iterator south_iter = south.begin();
			while( south_iter != south.end() )
			{
				int frame = (*south_iter).asInt();
				frame_list.push_back( frame );
			}

			Animation tmp_anim( name, frame_list );
			set.addAnimation( tmp_anim, Orientation::South );

			//Parse through north frames
			AnimationFrameList frame_list2;
			Json::Value north = anim["north"];
			Json::Value::iterator north_iter = north.begin();
			while( north_iter != south.end() )
			{
				int frame = (*north_iter).asInt();
				frame_list2.push_back( frame );
			}

			Animation tmp_anim2( name, frame_list2 );
			set.addAnimation( tmp_anim2, Orientation::North );
		}

		return set;



	}


};
