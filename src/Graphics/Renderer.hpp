#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Graphics/RenderableObject.hpp"
#include "SFML.hpp"

class Renderer
{
    public:
        
        static int init();
        static int render( RenderableObject* obj, int x, int y);
	static int render_tile();
        static int d_render( RenderableObject* obj, int x, int y);
        static int clear();

    private:

        static sf::RenderWindow window_;
};

#endif //RENDERER_HPP
