#include "Factory/UnitFactory.hpp"
#include "Resources/Preset/SpritePreset/UnitSpritePreset/SmallUnitSpritePreset.hpp"

Unit* UnitFactory::create( const std::string& name, UnitSize size, const std::string& spritePresetPath, const std::string& animationSetPresetPath )
{
	Unit* new_unit = new Unit();

	if( size == UnitSize::Small )
		new_unit->spritePreset_ = new SmallUnitSpritePreset();

	// Set general unit info
	new_unit->info.ID = UnitFactory::getInst().unitCount_++;
	new_unit->info.name = name;

	// Setup sprite preset
	new_unit->bindSpritePreset( new_unit->spritePreset_ );
	new_unit->spritePreset_->setPresetPath( spritePresetPath );

	// Setup animation preset
	AnimationSetPreset* anim_set_p = new AnimationSetPreset();
	anim_set_p->load( animationSetPresetPath );
	new_unit->setAnimationSet( anim_set_p->getAnimationSet() );
	delete anim_set_p;

	UnitFactory::getInst().managedUnits_.push_back( new_unit );

	return new_unit;
}

Unit* UnitFactory::get( unsigned int ID )
{

}

int UnitFactory::remove( unsigned int ID )
{

}

int UnitFactory::remove( Unit* unit )
{

}
