#include "IsometricTileComposite.hpp"

#include "Isometry.hh"

int IsometricTileComposite::add( IsometricTile* tile )
{
    tileComposite_.push_back( tile );
}

int IsometricTileComposite::add( IsometricTile* tile, int x, int y, int z )
{
    tile->coordinates.x = x;
    tile->coordinates.y = y;
    tile->coordinates.z = z;

    add( tile );
}
IsometricTile* IsometricTileComposite::getTile( int iter )
{
    return tileComposite_[iter];
}

IsometricTile* IsometricTileComposite::getTile( int x, int y )
{
    auto iter = tileComposite_.begin();
    IsometricTile* choosen = NULL;

    int highest_z = (*iter)->coordinates.z;
    while( iter != tileComposite_.end() )
    {
        if( (*iter)->coordinates.x != x || (*iter)->coordinates.y != y )
        {
            ++iter;
            continue;
        }

        if( (*iter)->coordinates.z >= highest_z ) choosen = *iter;
        ++iter;
    }

    return choosen;
}

IsometricTile* IsometricTileComposite::getTile( int x, int y, int z )
{
    auto iter = tileComposite_.begin();
    IsometricTile* choosen = NULL;

    while( iter != tileComposite_.end() )
    {
        if(     (*iter)->coordinates.x == x 
                && (*iter)->coordinates.y == y
                && (*iter)->coordinates.z == z )
        {
                choosen = *iter;
        }
        ++iter;
    }

    return choosen;
}

unsigned int IsometricTileComposite::getSize()
{
    return tileComposite_.size();
}
