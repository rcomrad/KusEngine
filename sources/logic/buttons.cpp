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
    this->setPo
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

void
lgc::Buttons::draw()
{
    for(auto& str : mButtonNames)
    {
        set
    }
}

void
lgc::Buttons::processEvent(gui::Event* aEvent)
{
    gui::MouseEvent* event = dynamic_cast<gui::MouseEvent*> (aEvent);

}

void
lgc::Buttons::update(float adTime)
{

}