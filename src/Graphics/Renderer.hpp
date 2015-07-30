#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "SFML.hpp"
#include "Utils.hh"

class IsometricTile;
class IsometricTileComposite;
class IsometricMap;
class RenderableObject;

class Renderer
{
	public:

		static int init();
		static int render( RenderableObject* obj, int x, int y);
		static int render( IsometricTile* tile, Tileset::Visibility vis = Tileset::Visibility::All, int off_x = 0, int off_y = 0 );
		static int render( IsometricTileComposite& composite, int off_x = 0, int off_y = 0 );
		static int render( IsometricMap& map, int off_x = 0, int off_y = 0 );
		static int clear();

	protected:

		static inline Renderer& getInstance() { static Renderer r; return r; }

		virtual int _init();
		virtual int _render( RenderableObject* obj, int x, int y );
		virtual int _render( IsometricTile* tile, Tileset::Visibility vis, int off_x, int off_y, bool rendTile = true, bool rendCliff = true );
		virtual int _render( IsometricTile* tile, Tileset::Visibility vis, int off_x, int off_y, bool rendTile, bool rendCliff, Orientation orient );
		virtual int _render( IsometricMap& map, int off_x, int off_y );

		virtual int _clear();

		sf::RenderWindow window_;
		sf::RenderTexture preMapTexture_;
		std::vector< sf::RenderTexture > textureLayers_;

		int baseX_;
		int baseY_;

		int dist_;
};

#endif //RENDERER_HPP
