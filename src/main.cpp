#include "Resources/Preset.hpp"
#include "Resources/Preset/SpritePreset.hpp"
#include "Resources/Preset/SpritePreset/UnitSpritePreset/SmallUnitSpritePreset.hpp"

#include "Animation/Animation.hpp"
#include "Animation/AnimatedObject.hpp"

#include "Unit/Unit/SmallUnit.hpp"

#include "Graphics/Renderer.hpp"

#include "Factory/UnitFactory.hpp"
#include "Factory/TileFactory.hpp"

#include "Utils/Resources/AnimationSetParser.hpp"
#include "Utils/Graphics/TextureUtils.hpp"

#include "Isometry/IsometricTile.hpp"

#include "SFML.hpp"

#include <thread>
#include <chrono>

std::string command;
std::vector< Unit* > units;
std::vector< IsometricTile* > tiles;
int unit_index = 0;
bool loop = true;

void print_intro()
{
	std::cout << "******************************" << std::endl;
	std::cout << "*  Unit animation prototype  *" << std::endl;
	std::cout << "*        v.0.1.0             *" << std::endl;
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
std::string anim_set_preset2( "../resources/AnimationSets/Unit/smallunit2.json" );

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

	Unit* archer2 = UnitFactory::create( "Luna", 
			UnitSize::Small2, 
			"../resources/Sprites/Unit/archer_2.0.png",
			anim_set_preset2 );

	units.push_back( wizard1 );
	units.push_back( archer1 );
	units.push_back( amazon1 );
	units.push_back( soldier1 );
	units.push_back( archer2 );

	TileFactory::load();
	IsometricTile* tile1 = TileFactory::create( "grass" );
	IsometricTile* tile2 = TileFactory::create( "dirt" );
	IsometricTile* tile3 = TileFactory::create( "long_grass" );

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

		for( int i = 0; i < 5; ++i )
		{
			for( int j = 0 ; j < 5; ++j )
			{
				tile2->coordinates.x = i;
				tile2->coordinates.y = j;
				tile2->setCliff( Tileset::Cliff::None );
				tile2->setCliffType( Tileset::CliffType::Rugged );
				if( j == 0 ) tile2->setCliff( Tileset::Cliff::Top, Orientation::South );
				if( j == 4 ) tile2->setCliff( Tileset::Cliff::Top, Orientation::North );
				if( i == 0 ) tile2->setCliff( Tileset::Cliff::Top, Orientation::West );
				if( i == 4 ) tile2->setCliff( Tileset::Cliff::Top, Orientation::East );

				Renderer::render( tile2, 200, 200 );
			}
		}

		for( int i = 1; i < 4; ++i )
		{
			for( int j = 1; j < 4; ++j )
			{
				tile1->setWeight( Tileset::Weight::Medium );
				tile1->coordinates.x = i;
				tile1->coordinates.y = j;

				Tileset::Weight weight = Tileset::Weight::Small;
				int w = (i+j) % 2;
				if( w == 0 ) weight = Tileset::Weight::Large;
				
				if( j == 1 ) tile1->setWeight( weight, Orientation::South );
				if( j == 3 ) tile1->setWeight( weight, Orientation::North );
				if( i == 1 ) tile1->setWeight( weight, Orientation::West );
				if( i == 3 ) tile1->setWeight( weight, Orientation::East );
				Renderer::render( tile1, 200, 200 );
			}
		}

		tile3->setWeight( Tileset::Weight::Large );
		tile3->coordinates.x = 2;
		tile3->coordinates.y = 2;
		Renderer::render( tile3, 200, 200 );

		TileFactory::updateTileType( tile2, "long_grass" );
		tile2->coordinates.x = 2;
		tile2->coordinates.y = 1;
		Renderer::render( tile2, 200, 200 );

		Renderer::render( wizard1, 100, 25 );
		Renderer::render( archer1, 200, 25 );
		Renderer::render( amazon1, 300, 25 );
		Renderer::render( soldier1, 400, 25 );
		Renderer::render( archer2, 500, 25 );

		Renderer::clear();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}


	return 0;
}
