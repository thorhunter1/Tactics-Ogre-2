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
    std::cout << "Available commands:" << std::endl;
    std::cout << "'help' - prints this" << std::endl;
    std::cout << "'exit' - exits application" <<  std::endl;
    std::cout << "'select - selects next unit" << std::endl;
    std::cout << "'rotate - rotates selected unit" << std::endl;
    std::cout << "'color_<color>' - sets unit team color" << std::endl;
    std::cout << " - available colors: red, green, blue, teal, gray, black" << std::endl;
    std::cout << "'anim_<anim>' sets unit animation" << std::endl;
    std::cout << "'- available animations: walk, stand, run, attack" << std::endl; 
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

    if( command == "color_red" )
        units[unit_index]->setTeamColor( TeamColor::Red );
    if( command == "color_green" )
        units[unit_index]->setTeamColor( TeamColor::Green );
    if( command == "color_blue" )
        units[unit_index]->setTeamColor( TeamColor::Blue );
    if( command == "color_teal" )
        units[unit_index]->setTeamColor( TeamColor::Teal );
    if( command == "color_black" )
        units[unit_index]->setTeamColor( TeamColor::Black );

    if( command == "anim_walk" )
        units[unit_index]->playAnimation( "walk", true );
    if( command == "anim_stand" )
        units[unit_index]->playAnimation( "stand", true );
    if( command == "anim_run" )
        units[unit_index]->playAnimation( "run", true );
    if( command == "anim_attack" )
        units[unit_index]->playAnimation( "attack", true );

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

int main()
{

    AnimationSet set = Parser::AnimationSetParser::parse( "../resources/AnimationSets/Unit/smallunit.json" );

    Unit* wizard1 =  UnitFactory::create( "Jim", UnitSize::Small, "../resources/Sprites/Unit/wizard.png" );
    Unit* amazon1 =  UnitFactory::create( "Amy", UnitSize::Small, "../resources/Sprites/Unit/amazon.png" );
    Unit* archer1 =  UnitFactory::create( "May", UnitSize::Small, "../resources/Sprites/Unit/archer.png" );
    Unit* soldier1 = UnitFactory::create( "Kim", UnitSize::Small, "../resources/Sprites/Unit/soldier.png" );

    units.push_back( wizard1 );
    units.push_back( archer1 );
    units.push_back( amazon1 );
    units.push_back( soldier1 );

    for( auto iter = units.begin(); iter != units.end(); ++iter )
    {
	    (*iter)->loadPresets();
	    (*iter)->setOrientation( Orientation::South );
	    (*iter)->playAnimation( "walk", true );
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
