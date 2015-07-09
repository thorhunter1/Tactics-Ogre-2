#ifndef IMAGE_UTILS_HPP
#define IMAGE_UTILS_HPP


#include "SFML.hpp"

enum class TeamColor;

namespace Graphics
{
    int teamColor( sf::Image& image, TeamColor color );
};

#endif //IMAGE_UTILS_HPP
