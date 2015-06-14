#include "Resources/Preset.hpp"
#include "Resources/Preset/SpritePreset.hpp"
#include "Resources/Preset/SpritePreset/UnitSpritePreset/SmallUnitSpritePreset.hpp"

#include "Animation/Animation.hpp"
#include "Animation/AnimatedObject.hpp"

#include "Unit/Unit/SmallUnit.hpp"

#include "SFML.hpp"

#include <thread>
#include <chrono>
int main()
{
    SpritePreset* unit_preset = new SmallUnitSpritePreset();
    unit_preset->Load( "amazon.png" );

    SmallUnit* First_unit = new SmallUnit();
    First_unit->setSpritePreset( unit_preset );

    First_unit->setOrientation( Orientation::West );
    First_unit->playAnimation( "walk", true );

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Close );

    int i = 0;

    while( window.isOpen() ) 
    {
        sf::Sprite sprite = First_unit->getRenderSprite();

        sprite.setPosition(100, 25);

        sprite.setScale( 2, 2 );

        window.clear();
        window.draw( sprite );

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(33));

        ++i;

        if( i == 100 ) First_unit->setOrientation( Orientation::North );
        if( i == 200 ) First_unit->setOrientation( Orientation::East );
        if( i == 300 ) First_unit->setOrientation( Orientation::South );
        if( i == 400 ) { First_unit->setOrientation( Orientation::West ); i = 0; }
    }


    return 0;
}
