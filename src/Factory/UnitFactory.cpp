#include "Factory/UnitFactory.hpp"

Unit* UnitFactory::create( std::string name, UnitSize size, std::string presetPath );
{
	Unit* new_unit = new Unit();

	if( size == UnitSize::Small )
		new_unit->spritePreset_ = new SmallUnitSpritePreset();

	// Set general unit info
	new_unit->info.ID = UnitFactory::getInst().unitCount_++;
	new_unit->info.name = name;

	// Setup sprite preset
	new_unit->bindSpritePreset( new_unit->spritePreset_ );
	new_unit->spritePreset_->setPresetPath( presetPath );

	UnitFactory::getInst().managedUnits_.push_back( new_unit );

	return new_unit;
}

Unit* UnitFactory::get( unsigned int ID );
{

}

int UnitFactory::remove( unsigned int ID );
{

}

int UnitFactory::remove( Unit* unit );
{

}
