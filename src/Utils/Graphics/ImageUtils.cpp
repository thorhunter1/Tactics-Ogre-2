#include "ImageUtils.hpp"

#include "Utils/Game/TeamColorEnum.hpp"

#include "SFML.hpp"

namespace Graphics
{
    int teamColor( sf::Image& image, TeamColor color )
    {
        float red_paint = 1.0;
        float green_paint = 1.0;
        float blue_paint = 1.0;
        //float alpha_paint = 1.0;

        if( color == TeamColor::Gray )  {}
        if( color == TeamColor::Red )   { red_paint = 1.0; green_paint = 0.5; blue_paint = 0.5; }
        if( color == TeamColor::Green ) { red_paint = 0.5; green_paint = 1.0; blue_paint = 0.5; }
        if( color == TeamColor::Blue )  { red_paint = 0.5; green_paint = 0.7; blue_paint = 1.0; }
        if( color == TeamColor::Teal )  { red_paint = 0.2; green_paint = 0.8; blue_paint = 1.0; }
        if( color == TeamColor::Black ) { red_paint = 0.5; green_paint = 0.5; blue_paint = 0.5; } 
        //if( color == TeamColor::Transparent ) { alpha_paint = 0.3; } 
        
        sf::Vector2u img_size = image.getSize();
        for( int iRows = 0; iRows < img_size.x; ++iRows )
        {
            for( int iCols = 0; iCols < img_size.y; ++iCols )
            {
                sf::Color pix = image.getPixel( iRows, iCols );
                //if( pix.r == pix.g && pix.r == pix.b )
                    //Debug( "r:" << (int)pix.r << " g:" << (int)pix.g << " b:" << (int)pix.b );
                //if( pix == LightGray || pix == MiddleGray || pix == DarkGray )
                if( pix.r == pix.g && pix.r == pix.b )
                {
                    pix.r *= red_paint;
                    pix.g *= green_paint;
                    pix.b *= blue_paint;
                    //pix.a *= alpha_paint;

                    image.setPixel( iRows, iCols, pix );
                }

            }
        }

    }
}
