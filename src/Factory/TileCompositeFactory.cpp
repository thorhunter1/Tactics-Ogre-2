#include "TileCompositeFactory.hpp"

#include "Isometry.hh"
#include "Factory.hh"

IsometricTileComposite TileCompositeFactory::create( const std::string& tileType, int width, int length, int height )
{
    TileCompositeFactory& f = TileCompositeFactory::getInstance();
    return f._create( tileType, width, length, height );
}

IsometricTileComposite TileCompositeFactory::_create( const std::string& tileType, int width, int length, int height )
{
    IsometricTileComposite comp;

    for( int iWidth = 0; iWidth < width; ++iWidth )
    {
        for( int iLength = 0; iLength < length; ++iLength )
        {
            for( int iHeight = 0; iHeight < height; ++iHeight )
            {
                IsometricTile* tile = TileFactory::create( tileType, iWidth, iLength, iHeight );
                tile->setWeight( Tileset::Weight::Medium );

                comp.add( tile );
            }
        }
    }

    return comp;
}
