#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Graphics/RenderableObject.hpp"
#include "Isometry/IsometricTile.hpp"

#include "SFML.hpp"

class Renderer
{
    public:
        
        static int init();
        static int render( RenderableObject* obj, int x, int y);
	static int render( IsometricTile* tile, int off_x, int off_y, int off_z );
        static int clear();

    protected:

	static inline Renderer& getInstance() { static Renderer r; return r; }
	
	virtual int _init();
	virtual int _render( RenderableObject* obj, int x, int y );
	virtual int _render( IsometricTile* tile, int off_x, int off_y, int off_z );
	virtual int _clear();

        sf::RenderWindow window_;
	std::vector< sf::RenderTexture > textureLayers_;
};

#endif //RENDERER_HPP
