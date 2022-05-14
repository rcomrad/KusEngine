#include "gui/gui_output_base.hpp"

#include "gui/drawable.hpp"
#include "gui/writable.hpp"

#define DELEMITER_BIT (16)

#define TAG_PART    (0b1111'1111'1111'1111)
#define LAYER_PART  (0b1111'1111'1111'1111 << DELEMITER_BIT)

gui::GuiOutputBase::GuiOutputBase() :
    mType           (GuiObjectType::NUN),
    mLayer          (0)
{}

gui::GuiOutputBase::~GuiOutputBase(){}

#define thisIsSprite    (sint_32(mType) & sint_32(GuiObjectType::SPRITE))
#define thisIsText      (sint_32(mType) & sint_32(GuiObjectType::TEXT))

#define thisToDrawable (dynamic_cast<Drawable*> (this))
#define thisToWritable (dynamic_cast<Writable*> (this))

void
gui::GuiOutputBase::draw()
{
    gui::Window::globalWindow.setView(mViewNumber);
    if (thisIsSprite)   thisToDrawable->draw();
    if (thisIsText)     thisToWritable->draw();
}

void
gui::GuiOutputBase::move(dom::Pair<float> aCoord)
{
    if (thisIsSprite)   thisToDrawable->move(aCoord);
    if (thisIsText)     thisToWritable->move(aCoord);
}

void
gui::GuiOutputBase::resetPosition(dom::Pair<float> aCoord)
{
    if (thisIsSprite)   thisToDrawable->resetPosition(aCoord);
    if (thisIsText)     thisToWritable->resetPosition(aCoord);
}

void
gui::GuiOutputBase::setScale(dom::Pair<float> aCoord)
{
    if (thisIsSprite)   thisToDrawable->setScale(aCoord);
    if (thisIsText)     thisToWritable->setScale(aCoord);
}

void
gui::GuiOutputBase::centrateViewOnObject(str_const_ref aViewName = "")
{
    sf_2f_val coord;
    if (thisIsSprite)   coord = thisToDrawable->getPosition();
    else                coord = thisToWritable->getPosition();
    if (aViewName.empty()) 
    {
        gui::Window::globalWindow.centrateView(mViewNumber, coord);
    }
}

bool 
gui::GuiOutputBase::operator<(const GuiOutputBase& aOther) const
{
    if (mLayer == aOther.mLayer) return this < &aOther;
    return mLayer < aOther.mLayer;
}

void 
gui::GuiOutputBase::setType(GuiObjectType aType)
{
    mType = GuiObjectType(sint_32(mType) | sint_32(aType));
}

void 
gui::GuiOutputBase::setLayer(str_const_ref aLayerName)
{
    //mLayer = aLayerNumber;
    mLayer &= TAG_PART;
    auto it = globalLayerNumbers.find(aLayerName);
    if (it == globalLayerNumbers.end())
    {
        globalLayerNumbers[aLayerName] = globalLayerNumbers.size();
        it = globalLayerNumbers.find(aLayerName);
    }
    mLayer |= it->second << DELEMITER_BIT;
}

void 
gui::GuiOutputBase::setTag(str_const_ref aTagName)
{
    //mLayer = aLayerNumber;
    mLayer &= LAYER_PART;
    auto it = globalTagNumbers.find(aTagName);
    if (it == globalTagNumbers.end())
    {
        globalTagNumbers[aTagName] = globalTagNumbers.size();
        it = globalTagNumbers.find(aTagName);
    }
    mLayer |= it->second;
}

void 
gui::GuiOutputBase::setView(str_const_ref aViewName)
{
    mViewNumber = gui::Window::globalWindow.getViewNumber(aViewName);
}

bool
gui::GuiOutputBaseComparator::operator() (GuiOutputBase* a, GuiOutputBase* b) const {
    return (*((GuiOutputBase*)a)) < (*((GuiOutputBase*)b));
}