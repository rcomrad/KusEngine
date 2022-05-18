#ifndef LOG_TYPES_HPP
#define LOG_TYPES_HPP

//--------------------------------------------------------------------------------

#include <set>

#include "gui/gui_output_base.hpp"

//#define SET_DRAWEBLE_TYPE std::set<sr::GuiOutputBase*, sr::GuiOutputBaseComparator>
typedef std::set<gui::GuiOutputBase*, gui::GuiOutputBaseComparator> SetDrawebleType;

typedef uint_16 tag_type;

//--------------------------------------------------------------------------------

#endif // !LOG_TYPES_HPP