#include "logic_object.hpp"

lgc::LogicObject::LogicObject()
{
    addTag("logical");
}

std::optional<uint_16>
lgc::LogicObject::processEvent(gui::Event* aEvent)
{
    return {};
}