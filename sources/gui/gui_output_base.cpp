#include "gui/gui_output_base.hpp"

#include "gui/drawable.hpp"
#include "gui/writable.hpp"

gui::GuiOutputBase::GuiOutputBase(uint_8 aLayer) :
    mType           (GuiOutputType::NUN),
    mLayer          (aLayer)
{}

gui::GuiOutputBase::~GuiOutputBase(){}

#define CALL_METHOD(type, class, method)\
    if (sint_32(mType) & sint_32(type)) dynamic_cast<class*> (this)->method

void
gui::GuiOutputBase::draw()
{
    CALL_METHOD(GuiOutputType::SPRITE, Drawable, draw());
    CALL_METHOD(GuiOutputType::SPRITE, Writable, draw());
    //if (int(mType) & 1) dynamic_cast<Drawable*> (this)->draw();
    //if (int(mType) & 2) dynamic_cast<Writable*> (this)->draw();
}

void
gui::GuiOutputBase::move(dom::Pair<float> aCoord)
{
    CALL_METHOD(GuiOutputType::SPRITE, Drawable, move(aCoord));
    CALL_METHOD(GuiOutputType::SPRITE, Writable, move(aCoord));
}

void
gui::GuiOutputBase::resetPosition(dom::Pair<float> aCoord)
{
    CALL_METHOD(GuiOutputType::SPRITE, Drawable, resetPosition(aCoord));
    CALL_METHOD(GuiOutputType::SPRITE, Writable, resetPosition(aCoord));
}

void
gui::GuiOutputBase::setScale(dom::Pair<float> aCoord)
{
    CALL_METHOD(GuiOutputType::SPRITE, Drawable, setScale(aCoord));
    CALL_METHOD(GuiOutputType::SPRITE, Writable, setScale(aCoord));
}

bool 
gui::GuiOutputBase::operator<(const GuiOutputBase& aOther) const
{
    if (mLayer == aOther.mLayer) return this < &aOther;
    return mLayer < aOther.mLayer;
}

void 
gui::GuiOutputBase::setType(GuiOutputType aType)
{
    mType = GuiOutputType(sint_32(mType) | sint_32(aType));
}

bool
gui::GuiOutputBaseComparator::operator() (GuiOutputBase* a, GuiOutputBase* b) const {
    return (*((GuiOutputBase*)a)) < (*((GuiOutputBase*)b));
}