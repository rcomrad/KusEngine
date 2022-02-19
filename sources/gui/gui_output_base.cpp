#include "gui/gui_output_base.hpp"

#include "gui/drawable.hpp"
#include "gui/writable.hpp"

sr::GuiOutputBase::GuiOutputBase
(
    GuiOutputType aType,
    uint_8 aLayer
) :
    mType(aType),
    mLayer(aLayer)
{
}

sr::GuiOutputBase::~GuiOutputBase(){}

void
sr::GuiOutputBase::draw()
{
    if (mType & 1) dynamic_cast<Drawable*> (this)->draw();
    if (mType & 2) dynamic_cast<Writable*> (this)->draw();
}

//bool
//sr::GuiOutputBaseComparator::operator() (void* a, void* b) const {
//    GuiOutputBase* bb = (GuiOutputBase*)b;
//    int nn;
//    return (*((GuiOutputBase*)a)) < (*((GuiOutputBase*)b));
//}

bool
sr::GuiOutputBaseComparator::operator() (GuiOutputBase* a, GuiOutputBase* b) const {
    GuiOutputBase* bb = (GuiOutputBase*)b;
    int nn;
    return (*((GuiOutputBase*)a)) < (*((GuiOutputBase*)b));
}


bool 
sr::GuiOutputBase::operator<(const GuiOutputBase& aOther) const
{
    if (mLayer == aOther.mLayer) return this < &aOther;
    return mLayer < aOther.mLayer;
}