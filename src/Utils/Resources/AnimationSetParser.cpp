#include "json/json.h"

#include "Utils/Resources/AnimationSetParser.hpp"
#include "Utils/Debug/DebugUtils.hpp"

#include <fstream>

namespace Parser
{

	AnimationSet AnimationSetParser::parse( const std::string& path )
	{
		AnimationSet set;

		try
		{
			Json::Value root;
			Json::Reader reader;

			std::ifstream document( path, std::ifstream::binary );

			bool ret = reader.parse( document, root, false );

			Json::Value animation_set = root["animation_set"];

			// Parse through all animations
			Json::Value::iterator iter = animation_set.begin();

			while( iter != animation_set.end() )
			{
				Debug( "here2" );
				Json::Value anim = (*iter);
				++iter;

				std::string name = anim["name"].asString();
				Debug( name );

				//Parse through south frames
				AnimationFrameList frame_list;
				Json::Value south = anim["south"];
				Debug( south );
				Json::Value::iterator south_iter = south.begin();
				while( south_iter != south.end() )
				{
					int frame = (*south_iter).asInt();
					Debug( frame );
					frame_list.push_back( frame );
					++south_iter;
				}

				Animation tmp_anim( name, frame_list );
				set.addAnimation( tmp_anim, Orientation::South );
				set.addAnimation( tmp_anim, Orientation::West ); //Currently easiest way to do it

				//Parse through north frames
				AnimationFrameList frame_list2;
				Json::Value north = anim["north"];
				Json::Value::iterator north_iter = north.begin();
				while( north_iter != north.end() )
				{
					int frame = (*north_iter).asInt();
					frame_list2.push_back( frame );
					++north_iter;
				}

				Animation tmp_anim2( name, frame_list2 );
				set.addAnimation( tmp_anim2, Orientation::North );
				set.addAnimation( tmp_anim2, Orientation::East ); //same as with West
			}
		}
		catch(...)
		{
			Error( path << " parsing error" );
			set = AnimationSet::None;
		}

		return set;



	}


};