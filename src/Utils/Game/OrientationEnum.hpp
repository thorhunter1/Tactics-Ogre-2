#ifndef ORIENTATION_ENUM_HPP
#define ORIENTATION_ENUM_HPP

enum class Orientation { North, South, East, West, None };

inline std::string enum_print( Orientation orient )
{
    std::string tmp_string;

    if( orient == Orientation::North ) tmp_string = std::string( "North" );
    if( orient == Orientation::South ) tmp_string = std::string( "South" );
    if( orient == Orientation::West ) tmp_string = std::string( "West" );
    if( orient == Orientation::East ) tmp_string = std::string( "East" );
    if( orient == Orientation::None ) tmp_string = std::string( "None" );

    return tmp_string;
}

#endif //ORIENTATION_ENUM_HPP
