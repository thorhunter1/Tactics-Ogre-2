#ifndef UNIT_ENUM_HPP
#define UNIT_ENUM_HPP

enum class UnitSize { 	Small, 
			Large 
};

namespace MovementType
{
enum UnitMoveType { 	Normal 		= 1 << 0,
			Swimming	= 1 << 1,
			WaterWalking 	= 1 << 2,
			Amphibious	= 1 << 3,
			Flying 		= 1 << 4,
			Floating	= 1 << 5,
			Teleporting	= 1 << 6
};

};

#endif //UNIT_ENUM_HPP
