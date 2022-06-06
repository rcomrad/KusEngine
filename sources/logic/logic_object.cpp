#include "logic_object.hpp"

void
lgc::LogicObject::create()
{
    this->addTag("logical");
}

std::optional<uint_16>
lgc::LogicObject::processEvent(gui::Event* aEvent)
{
    return {};
}