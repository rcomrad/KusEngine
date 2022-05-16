#include "gui/gui_output_base.hpp"

#include "gui/drawable.hpp"
#include "gui/writable.hpp"

// #define DELEMITER_BIT (16)

// #define TAG_PART    (0b1111'1111'1111'1111)
// #define LAYER_PART  (0b1111'1111'1111'1111 << DELEMITER_BIT)

std::map<std::string, layer_type> gui::GuiOutputBase::globalLayerNumbers =
{
    //{"Default", TAG_PART}
    {"Default", 255}
};
// std::map<std::string, uint_16> gui::GuiOutputBase::globalTagNumbers =
// {
//     {"Default", TAG_PART}
// };

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

gui::GuiOutputBase::PositionUnion 
gui::GuiOutputBase::getPosition()
{
    if (thisIsSprite)   return {thisToDrawable->getSpritePosition()};
    else                return {thisToWritable->getTextPosition()};
}

void
gui::GuiOutputBase::centrateViewOnObject(str_const_ref aViewName)
{
    sf_2f_val coord;
    if (thisIsSprite)   coord = thisToDrawable->getSpritePosition();
    else                coord = thisToWritable->getTextPosition();
    if (aViewName.empty()) 
    {
        gui::Window::globalWindow.centrateView(mViewNumber, coord);
    }
}

bool 
gui::GuiOutputBase::operator<(const GuiOutputBase& aOther) const
{
    if (mLayer  != aOther.mLayer)   return mLayer   < aOther.mLayer;
    // if (mTag    != aOther.mTag  )   return mTag     < aOther.mTag;
    return this < &aOther;
}

void 
gui::GuiOutputBase::addLayer(const dom::Pair<const char*, layer_type>& aLayer)
{
    //std::vector<dom::Pair<str_val, layer_type>> temp{aLayer};
    addLayer(std::vector<dom::Pair<const char*, layer_type>> {aLayer});
}

void 
gui::GuiOutputBase::addLayer(const std::vector<dom::Pair<const char*, layer_type>>& aLayerArray)
{
    addComponentToDictionary(globalLayerNumbers, aLayerArray);
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
    // mLayer &= TAG_PART;
    // uint_16 num = getComponentNumber(globalLayerNumbers, aLayerName);
    // mLayer |= num << DELEMITER_BIT;
    mLayer = getComponentNumber(globalLayerNumbers, aLayerName);
}

// void 
// gui::GuiOutputBase::setTag(str_const_ref aTagName)
// {
//     //mLayer = aLayerNumber;
//     // mLayer &= LAYER_PART;
//     // uint_16 num = getComponentNumber(globalTagNumbers, aTagName);
//     // mLayer |= num;
//     mTag = getComponentNumber(globalTagNumbers, aTagName);
// }

void 
gui::GuiOutputBase::setView(str_const_ref aViewName)
{
    mViewNumber = gui::Window::globalWindow.getViewNumber(aViewName);
}

// gui::GuiOutputBase::PositionUnion::PositionUnion(sf_2f_val aSfmlPos)
// {
//     domPos = {aSfmlPos.x, aSfmlPos.y};
// }

// gui::GuiOutputBase::PositionUnion::PositionUnion(dom::Pair<float> aDomPos)
// {
//     sfmlPos = {aDomPos.x, aDomPos.y};
// }

gui::GuiOutputBase::PositionUnion::operator sf_2f_val()
{
    return sfmlPos;
}

gui::GuiOutputBase::PositionUnion::operator dom::Pair<float>()
{
    return  {sfmlPos.x, sfmlPos.y};
}

void 
gui::GuiOutputBase::addComponentToDictionary
(
    std::map<str_val, layer_type>& aDictionary,
    const std::vector<dom::Pair<const char*, layer_type>>& aComponentArray
)
{
    for(auto& newComponent : aComponentArray)
    {
        #ifdef _DBG_
        for(auto& existComponent : aDictionary)
        {
            if (existComponent.second == newComponent.second)
            {
                dom::ErrorMessages::writeError
                (
                    "Component_number_is_already_occupied_in_dictionary", 
                    "Component_name:",
                    newComponent.first, 
                    "Component_number:",
                    newComponent.second,
                    "Existing_component_name:",
                    existComponent.first
                );          
            }
        }
        #endif

        aDictionary[newComponent.first] = newComponent.second;
    }
}

layer_type 
gui::GuiOutputBase::getComponentNumber
(
    const std::map<str_val, layer_type>& aDictionary,
    str_const_ref aComponentName
)
{
    auto result = aDictionary.find(aComponentName);
    if (result == aDictionary.end())
    {
        #ifdef _DBG_
            dom::ErrorMessages::writeError
            (
                "Dictionary_lack_the_component", 
                "Component_name:",
                aComponentName
            );          
        #endif
        result = globalLayerNumbers.find("Default");
    }
    return result->second;
}

bool
gui::GuiOutputBaseComparator::operator() (GuiOutputBase* a, GuiOutputBase* b) const {
    return (*((GuiOutputBase*)a)) < (*((GuiOutputBase*)b));
}