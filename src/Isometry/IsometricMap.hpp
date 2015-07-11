#ifndef ISOMETRIC_MAP_HPP
#define ISOMETRIC_MAP_HPP

class IsometricTile;
class IsometricTileComposite;

class IsometricMap
{
	public:
		sf::Vector3f getSize();

		int add( IsometricTile* tile );
		int add( IsometricTile* tile, int x, int y, int z );
		int add( IsometricTileComposite* comp );
		int add( IsometricTileComposite* comp, int x, int y, int z );

		IsometricTile* getTile( int x, int y );
		IsometricTile* getTile( int x, int y, int z );

	protected:

        sf::Vector3f size_;
		std::map< int, std::map< int, std::map< int, IsometricTile* > > > tileMap_;
};

#endif //ISOMETRIC_MAP_HPP
