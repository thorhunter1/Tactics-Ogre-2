#ifndef RENDERABLE_OBJECT_HPP
#define RENDERABLE_OBJECT_HPP

#include "Utils/Game/TeamColorEnum.hpp"

#include "SFML.hpp"

class RenderableObject
{
    friend class Renderer;

    public:
        
        RenderableObject();

        /// Team Color
        int 		setTeamColor( TeamColor color );
	TeamColor 	getTeamColor();

        /// Sprite
	int 		setRenderSprite( const sf::Sprite& sprite );
        sf::Sprite 	getRenderSprite();

        /// Updates texture
        int updateTexture(); 				//from renderImage_
        int updateTexture( const sf::Image& image );	//from image
	int updateTexture( const sf::Uint8* pixels, 	//from pixel array
			unsigned int width, 
			unsigned int height, 
			unsigned int x, 
			unsigned int y );

        /// Binds renderImage_ to external image
        virtual int bindRenderImage( const sf::Image& image );

    protected:

        sf::Image   renderImage_;
        sf::Texture renderTexture_;
        sf::Sprite  renderSprite_;
        TeamColor   teamColor_;

        bool        fUpdateTexture_;
        bool        fUseTeamColor_;
        
};

#endif // RENDERABLE_OBJECT_HPP
