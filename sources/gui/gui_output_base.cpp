#include "gui/gui_output_base.hpp"

#include "gui/drawable.hpp"
#include "gui/writable.hpp"

sr::GuiOutputBase::GuiOutputBase
(
    uint_8 aLayer, 
    Pair<float> aCoordOffset
) :
    mType           (GuiOutputType::NUN),
    mLayer          (aLayer),
    mCoordOffset    (aCoordOffset)
{}

sr::GuiOutputBase::~GuiOutputBase(){}

void
sr::GuiOutputBase::draw()
{
    if (int(mType) & 1) dynamic_cast<Drawable*> (this)->draw();
    if (int(mType) & 2) dynamic_cast<Writable*> (this)->draw();
}

bool 
sr::GuiOutputBase::operator<(const GuiOutputBase& aOther) const
{
    if (mLayer == aOther.mLayer) return this < &aOther;
    return mLayer < aOther.mLayer;
}

void 
sr::GuiOutputBase::setType(GuiOutputType aType)
{
    mType = GuiOutputType(int(mType) + int(aType));
}

bool
sr::GuiOutputBaseComparator::operator() (GuiOutputBase* a, GuiOutputBase* b) const {
    GuiOutputBase* bb = (GuiOutputBase*)b;
    int nn;
    return (*((GuiOutputBase*)a)) < (*((GuiOutputBase*)b));
}