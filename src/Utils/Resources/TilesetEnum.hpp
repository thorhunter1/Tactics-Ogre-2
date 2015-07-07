#ifndef TILESET_ENUM_HPP
#define TILESET_ENUM_HPP

namespace Tileset
{
	//enum class Type { Dirt, Grass, LongGrass };
	enum class Cliff { Top, Bottom, None };
	enum class CliffType { Smooth, Rugged };
	enum class Weight { Small, Medium, Large };

	struct TileInfo
	{
		Cliff 		cliff;
		CliffType	cliff_type;
		Weight		weight;
	};
}

#endif //TILESET_ENUM_HPP
