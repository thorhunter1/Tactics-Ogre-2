#ifndef IMAGE_UTILS_HPP
#define IMAGE_UTILS_HPP

#include "SFML"
#include "Utils/Game/TeamColorEnum.hpp"

namespace Graphics
{
    const sf::Color LightGray = sf::Color( 66, 66, 66 );
    const sf::Color MiddleGray = sf::Color( 125, 125, 125 );
    const sf::Color LightGray = sf::color( 175, 175, 175 );

    teamColor( sf::Image& image, TeamColor color )
    {
        float red_paint = 1.0;
        float green_paint = 1.0;
        float blue_paint = 1.0;

        if( color == TeamColor::Gray )  {}
        if( color == TeamColor::Red )   { red_paint = 1.0; green_paint = 0.0; blue_paint = 0.0; }
        if( color == TeamColor::Green ) { red_paint = 0.0; green_paint = 1.0; blue_paint = 0.0; }
        if( color == TeamColor::Blue )  { red_paint = 0.0; green_paint = 1.0; blue_paint = 1.0; }
        if( color == TeamColor::Teal )  { red_paint = 0.0; green_paint = 1.0; blue_paint = 1.0; }
        if( color == TeamColor::Black ) { red_paint = 0.3; green_paint = 0.3; blue_paint = 0.3; } 
        
        sf::Vector2u img_size = image.getSize();
        for( int iRows = 0; iRows < img_size.x; ++iRows )
        {
            for( int iCols = 0; iCols < img_size.y; ++iCols )
            {
                sf::Color pix = image.getPixel( iRows, iCols );
                if( pix == LightGray || pix == MiddleGray || pix == DarkGray )
                {
                    pix.r *= red_paint;
                    pix.g *= green_paint;
                    pix.b *= blue_paint;

                    image.setPixel( iRows, iCols, pix );
                }

            }
        }

    }
}
