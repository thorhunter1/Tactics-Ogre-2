#ifndef TILESET_ENUM_HPP
#define TILESET_ENUM_HPP

template<class T> inline T operator~ (T a) { return (T)~(int)a; }
template<class T> inline T operator| (T a, T b) { return (T)((int)a | (int)b); }
template<class T> inline T operator& (T a, T b) { return (T)((int)a & (int)b); }
template<class T> inline T operator^ (T a, T b) { return (T)((int)a ^ (int)b); }
template<class T> inline T& operator|= (T& a, T b) { return (T&)((int&)a |= (int)b); }
template<class T> inline T& operator&= (T& a, T b) { return (T&)((int&)a &= (int)b); }
template<class T> inline T& operator^= (T& a, T b) { return (T&)((int&)a ^= (int)b); }

namespace Tileset
{
	enum class Cliff { Top, Bottom, Middle, TopBottom, None };
	enum class CliffType { Smooth, Rugged };
	enum class Weight { Small, Medium, Large, Full };

    enum Visibility {   TileNorth   = 1 << 0,
                        TileSouth   = 1 << 1,
                        TileWest    = 1 << 2,
                        TileEast    = 1 << 3,
                        CliffNorth  = 1 << 4,
                        CliffSouth  = 1 << 5,
                        CliffWest   = 1 << 6,
                        CliffEast   = 1 << 7,
                        TileAll     = TileNorth | TileSouth | TileWest | TileEast,
                        CliffAll    = CliffNorth | CliffSouth | CliffWest | CliffEast,
                        All         = TileAll | CliffAll
    };

	struct TileInfo
	{
        Cliff 		cliff;
		CliffType	cliff_type;
		Weight		weight;
	};
}

#endif //TILESET_ENUM_HPP
