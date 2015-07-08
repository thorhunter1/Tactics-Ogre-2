#ifndef ISOMETRIC_TILE_COMPOSITE_HPP
#define ISOMETRIC_TILE_COMPOSITE_HPP

class IsometricMapComposite
{
	public:
		int add( IsometricTile* tile );
		int add( IsometricTile* tile, int x, int y, int z );

		IsometricTile* getTile( int x, int y );
		IsometricTile* getTile( int x, int y, int z );

	protected:
		int x_;
		int y_;
		int z_;

		std::map< int, std::map< int, std::map< int, IsometricTile* > > > tileComposite_;
}

#endif //ISOMETRIC_TILE_COMPISITE_HPP
