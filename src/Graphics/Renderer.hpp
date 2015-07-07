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
	    static int render( IsometricTile* tile, int x, int y );
        static int d_render( RenderableObject* obj, int x, int y);
        static int clear();

    private:

        static sf::RenderWindow window_;
};

#endif //RENDERER_HPP
