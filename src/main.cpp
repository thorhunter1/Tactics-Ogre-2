#include "Resources/Preset.hpp"
#include "Resources/Preset/SpritePreset.hpp"
#include "Resources/Preset/SpritePreset/UnitSpritePreset/SmallUnitSpritePreset.hpp"

#include "Animation/Animation.hpp"
#include "Animation/AnimatedObject.hpp"

#include "Unit/Unit/SmallUnit.hpp"

#include "Graphics/Renderer.hpp"

#include "Factory/UnitFactory.hpp"

#include "Utils/Resources/AnimationSetParser.hpp"

#include "SFML.hpp"

#include <thread>
#include <chrono>

std::string command;
std::vector< Unit* > units;
int unit_index = 0;
bool loop = true;

void print_intro()
{
	std::cout << "******************************" << std::endl;
	std::cout << "*  Unit animation prototype  *" << std::endl;
	std::cout << "*        v.0.0.1             *" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << std::endl;
}

void print_commands()
{
	std::cout << "Available commands:" << std::endl << std::endl;

	std::cout << "'help'      - prints this" << std::endl;
	std::cout << "'exit'      - exits application" <<  std::endl;
	std::cout << "'select'    - selects next unit" << std::endl;
	std::cout << "'rotate'    - rotates selected unit" << std::endl;
	std::cout << "'color'     - sets unit team color" << std::endl;
	std::cout << "'anim'      - sets unit animation" << std::endl;
	std::cout << "'loop'      - makes units execute animation in loop" << std::endl;
}

void set_color()
{
	std::string color;

	std::cout << "Select color (red, green, blue, teal, black, gray): ";
	std::cin >> color;

	if( color == "red" )
		units[unit_index]->setTeamColor( TeamColor::Red );
	if( color == "green" )
		units[unit_index]->setTeamColor( TeamColor::Green );
	if( color == "blue" )
		units[unit_index]->setTeamColor( TeamColor::Blue );
	if( color == "teal" )
		units[unit_index]->setTeamColor( TeamColor::Teal );
	if( color == "black" )
		units[unit_index]->setTeamColor( TeamColor::Black );
	if( color == "gray" )
		units[unit_index]->setTeamColor( TeamColor::Gray );
}

void set_anim()
{
	std::string anim;

	std::cout << "Select animation (walk, run, attack etc.): ";
	std::cin >> anim;
	units[unit_index]->playAnimation( anim, loop );
}

int parse_command()
{
	int ret = 0;

	if( command == "help" ) 
		print_commands();

	if( command == "exit" )
		exit(0);

	if( command == "select" )
	{
		unit_index++;
		if( unit_index >= units.size() ) unit_index = 0;
		std::cout << "selected unit " << unit_index << std::endl;
	}

	if( command == "rotate" )
		units[unit_index]->rotate();

	if( command == "color" )
		set_color();

	if( command == "anim" )
		set_anim();
	if( command == "loop" )
	{
		loop = !loop;
		if( loop ) std::cout << "Loop enabled. Next 'anim' command will loop" << std::endl;
		else	std::cout << "Loop disabled. Next 'anim' command won't loop" << std::endl;
	}

	return ret;
}

void get_command()
{
	std::cout << "> ";
	std::cin >> command;

	int ret = parse_command();
	if( ret !=0 ) exit(0);
	else get_command();
}

void cmd_init()
{
	print_intro();
	print_commands();
	get_command();
}

std::string anim_set_preset( "../resources/AnimationSets/Unit/smallunit.json" );
int main()
{


	//AnimationSet set = Parser::AnimationSetParser::parse( "../resources/AnimationSets/Unit/smallunit.json" );

	Unit* wizard1 = UnitFactory::create( 
			"Jim", 
			UnitSize::Small, 
			"../resources/Sprites/Unit/wizard.png",
			anim_set_preset );

	Unit* amazon1 = UnitFactory::create( 
			"Amy", 
			UnitSize::Small,
			"../resources/Sprites/Unit/amazon.png",
			anim_set_preset );

	Unit* archer1 = UnitFactory::create( 
			"May", 
			UnitSize::Small, 
			"../resources/Sprites/Unit/archer.png",
			anim_set_preset );

	Unit* soldier1 = UnitFactory::create( "Kim", 
			UnitSize::Small, 
			"../resources/Sprites/Unit/soldier.png",
			anim_set_preset );

	units.push_back( wizard1 );
	units.push_back( archer1 );
	units.push_back( amazon1 );
	units.push_back( soldier1 );

	for( auto iter = units.begin(); iter != units.end(); ++iter )
	{
		(*iter)->loadPresets();
		(*iter)->setOrientation( Orientation::South );
		(*iter)->playAnimation( "walk", loop );
	}

	std::thread cmd_thr( cmd_init );

	Renderer::init();

	int i = 0;

	while( true ) 
	{
		Renderer::render( wizard1, 100, 25 );
		Renderer::render( archer1, 200, 25 );
		Renderer::render( amazon1, 300, 25 );
		Renderer::render( soldier1, 400, 25 );

		Renderer::clear();

		std::this_thread::sleep_for(std::chrono::milliseconds(33));
	}


	return 0;
}
