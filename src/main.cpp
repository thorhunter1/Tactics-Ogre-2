#include "Resources.hh"
#include "Animation.hh"
#include "Unit.hh"
#include "Graphics.hh"
#include "Factory.hh"
#include "Utils.hh"
#include "Isometry.hh"

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

    IsometricTileComposite dirt_comp = TileCompositeFactory::create( "dirt", 3, 3, 2 );
    IsometricTileComposite grass_comp = TileCompositeFactory::create( "grass", 10, 10, 4 );
    IsometricTileComposite grass_comp3 = TileCompositeFactory::create( "grass", 8, 8, 3 );
    IsometricTileComposite grass_comp2 = TileCompositeFactory::create( "grass", 2, 2, 2 );
    IsometricTileComposite long_grass_comp = TileCompositeFactory::create( "long_grass", 1, 1, 4 );
    IsometricTileComposite dirt_comp2 = TileCompositeFactory::create( "dirt", 3, 4, 4 );
    IsometricTileComposite grass_comp4 = TileCompositeFactory::create( "grass", 3, 4, 2 );
    
    IsometricMap map1;
    map1.setSize( 30, 30, 30 );
    map1.add( &dirt_comp );
    map1.add( &grass_comp, 2, 2);
    map1.add( &grass_comp2 );
    map1.add( &grass_comp3 );
    map1.add( &grass_comp4, 0, 7 );
    map1.add( &long_grass_comp );
    map1.add( &dirt_comp2, 3, 3 );

    Isometry::smoothMap( &map1 );

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
        Renderer::render( map1, 500, 500 );
        //Renderer::render( dirt_comp, 400, 300 );
        //Renderer::render( grass_comp, 400, 300 );
        //Renderer::render( long_grass_comp, 200, 200 );
		
        Renderer::render( wizard1, 100, 25 );
		Renderer::render( archer1, 200, 25 );
		Renderer::render( amazon1, 300, 25 );
		Renderer::render( soldier1, 400, 25 );
		Renderer::render( archer2, 500, 25 );

		Renderer::clear();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}


	return 0;
}
