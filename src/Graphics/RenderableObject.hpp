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

	/// Gets sprite of whole texture
	sf::Sprite d_getTextureSprite();

        /// Updates renderTexture_ from renderImage_
        int updateTexture();

        /// Updates renderTexture_ from external source
        int updateTexture( const sf::Image& image );

	/// Updates renderTexture_ with array of pixels
	int updateTexture( const sf::Uint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y );

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
