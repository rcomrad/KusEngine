#include "buttons.hpp"

lgc::Buttons::Buttons
(
    str_const_ref aTexturePath, 
    std::vector<str_val> aButtonsNames,
    dom::Pair<float> aStartPosition,
    dom::Pair<float> mPositionChange
) :
    DrawableAndWritable (aTexturePath),
    mButtonNames        (aButtonsNames),
    mStartPosition      (aStartPosition),
    mPositionChange     (mPositionChange)
{
    mButtonSize = this->getSpriteSize();
    this->setLayer("Button");
    this->setView("Player");
    addTag("Button");
    setStartPosition({100., 100.});
    setPositionChange({0., 30.});
}

void
lgc::Buttons::setButtonNames(const std::vector<str_val>& aButtonsNames)
{
    mButtonNames = aButtonsNames;
}

void
lgc::Buttons::setStartPosition(dom::Pair<float> aStartPosition)
{
    mStartPosition = aStartPosition;
}

void
lgc::Buttons::setButtonSize(dom::Pair<float> aButtonSize)
{
    mButtonSize = aButtonSize;
}

void
lgc::Buttons::setPositionChange(dom::Pair<float> aPositionChange)
{
    mPositionChange = aPositionChange;
}

#include <iostream>
void
lgc::Buttons::draw()
{
    dom::Pair<float> offset = mPositionChange;
    if (offset.x) offset.x += mButtonSize.x;
    if (offset.y) offset.y += mButtonSize.y;

    dom::Pair<float> position = mStartPosition;
    for(auto& str : mButtonNames)
    {
        //std::cout << position.x << " " << position.y << "\n";
        this->setPosition(position);
        this->setText(str);
        this->GuiOutputBase::draw();
        position += offset;
    }
}

std::optional<uint_16>
lgc::Buttons::processEvent(gui::Event* aEvent)
{
	if (aEvent->getEventType() != gui::Event::EventType::MOUSE_RELEASED)
	{
        return {};
    }

    gui::MouseEvent* event = dynamic_cast<gui::MouseEvent*> (aEvent);
    auto mousePos = event->getPosition();

    dom::Pair<float> offset = mPositionChange;
    if (offset.x) offset.x += mButtonSize.x;
    if (offset.y) offset.y += mButtonSize.y;

    dom::Pair<float> position = mStartPosition;
    
    for(int i = 0; i < mButtonNames.size(); ++i)
    {
        if (position.x <= mousePos.x && position.x + mButtonSize.x <= mousePos.x
            && position.y <= mousePos.y && position.y + mButtonSize.y <= mousePos.y)
        {
            return i;
        }
    }

    return {};
}

void
lgc::Buttons::update(float adTime)
{

}