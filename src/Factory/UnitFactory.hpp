#ifndef UNIT_FACTORY_HPP
#define UNIT_FACTORY_HPP

#include "Utils/Game/UnitEnum.hpp"

#include "Unit/Unit.hpp"

class UnitFactory
{
	public:
		static Unit* create( std::string name, UnitSize size, std::string presetPath );
		static Unit* get( unsigned int ID );
		static int remove( unsigned int ID );
		static int remove( Unit* unit );

	protected:
		static inline UnitFactory& getInst() { static UnitFactory unit_factory; return unit_factory; }

	private:
		unsigned int unitCount_ = 0;
		std::vector< Unit* > managedUnits_;
};

#endif //UNIT_FACTORY_HPP
