#include "IsometricTileComposite.hpp"

#include "Isometry.hh"

int IsometricTileComposite::add( IsometricTile* tile )
{
    tileComposite_.push_back( tile );
}

int IsometricTileComposite::add( IsometricTile* tile, int x, int y, int z )
{
    tile->setPosition( x, y, z );

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

    int highest_z = (*iter)->getPosition().z;
    while( iter != tileComposite_.end() )
    {
        if( (*iter)->getPosition().x != x || (*iter)->getPosition().y != y )
        {
            ++iter;
            continue;
        }

        if( (*iter)->getPosition().z >= highest_z ) choosen = *iter;
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
        if(     (*iter)->getPosition().x == x 
                && (*iter)->getPosition().y == y
                && (*iter)->getPosition().z == z )
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
