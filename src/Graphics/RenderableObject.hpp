#ifndef RENDERABLE_OBJECT_HPP
#define RENDERABLE_OBJECT_HPP

#include "Utils/Game/TeamColorEnum.hpp"

#include "SFML.hpp"

class RenderableObject
{
    public:
        
        sf::Sprite getSprite() { return renderSprite_; }

    protected:

        sf::Texture renderTexture_;
        sf::Sprite  renderSprite_;

        TeamColor teamColor_;
        
};

#endif // RENDERABLE_OBJECT_HPP
