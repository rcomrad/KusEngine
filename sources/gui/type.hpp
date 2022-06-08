#ifndef GUI_TYPES
#define GUI_TYPES

//#include "domain/"

#include <set>

#include <SFML/Graphics.hpp>

#include "event.hpp"

typedef const sf::Vector2f&     sf_2f_const_ref;
typedef sf::Vector2f            sf_2f_val;

typedef uint_8                  layer_type;
typedef uint_8                  view_type;

typedef std::vector<gui::Event*> EventArray;

#endif // !GUI_TYPES