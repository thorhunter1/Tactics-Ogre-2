#ifndef RENDERABLE_OBJECT_HPP
#define RENDERABLE_OBJECT_HPP

#include "Utils/Game/TeamColorEnum.hpp"

#include "SFML.hpp"

class RenderableObject
{
    friend class Renderer;

    public:
        
        RenderableObject();

        /// Sets teamcolor
        int setTeamColor( TeamColor color );

        /// Gets current sprite to render
        sf::Sprite getRenderSprite();

        /// Updates renderTexture_ from renderImage_
        int updateTexture();

        /// Updates renderTexture_ from external source
        int updateTexture( const sf::Image& image );

    protected:

        /// Binds renderImage_ to external image
        virtual int bindRenderImage( const sf::Image& image );

        sf::Image   renderImage_;
        sf::Texture renderTexture_;
        sf::Sprite  renderSprite_;
        TeamColor   teamColor_;

        bool        fUpdateTexture_;
        bool        fUseTeamColor_;
        
};

#endif // RENDERABLE_OBJECT_HPP
