#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Graphics/RenderableObject.hpp"

class Renderer
{
    public:
        
        static int render( RenderableObject* obj, int x, int y);
};

#endif //RENDERER_HPP
