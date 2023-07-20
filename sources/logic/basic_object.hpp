#ifndef BASIC_OBJECT_HPP
#define BASIC_OBJECT_HPP

#include <vector>

#include "domain/holy_trinity.hpp"

#include "file/variable.hpp"
#include "gui/gui_object.hpp"

namespace lgc
{
class Object : public gui::GUIObject
{
public:
    Object(const file::VariableArray& aVariables);
    HOLY_TRINITY_MOST(Object);

    bool interact(const event::MouseEvent& aEvent) noexcept;

private:
    // std::set<tag_type> mTags;

    std::vector<int> mOnClick;
    std::vector<int> mmOnGaze;
    std::vector<int> mUpdate;


    void setOnClickAction(const std::string& aActionStr) noexcept;
};
} // namespace lgc

#endif // !BASIC_OBJECT_HPP
