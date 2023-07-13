#include "basic_object.hpp"

// std::map<std::string, layer_type> gui::BasicObject::globalLayerNumbers =
// {
//     {"Default", 250}
// };

gui::BasicObject::BasicObject(const std::string& aTextureName) noexcept
{
    mTexture.loadFromFile(aTextureName);
    mSprite.setTexture(mTexture);
}

// void
// gui::BasicObject::create()
// {
//     this->addTag(DRAWABLE_TAG);
// }

// #define thisIsSprite    (sint_32(mType) & sint_32(GuiObjectType::SPRITE))
// #define thisIsText      (sint_32(mType) & sint_32(GuiObjectType::TEXT))

// #define thisToDrawable  (dynamic_cast<Drawable*> (this))
// #define thisToWritable  (dynamic_cast<Writable*> (this))

void
gui::BasicObject::draw(gui::Window& aWindow) const noexcept
{
    aWindow.draw(mSprite);
}

void
gui::BasicObject::move(const dom::Pair<float>& aCoord) noexcept
{
    mSprite.move({aCoord.x, aCoord.y});
}

void
gui::BasicObject::setPosition(const dom::Pair<float>& aCoord) noexcept
{
    mSprite.setPosition(sf::Vector2f(aCoord.x, aCoord.y));
}

// void
// gui::BasicObject::resetPosition(dom::Pair<float> aCoord)
// {
//     mSprite.setPosition(
//         {(aCoord.x - mPositionOffset.x), (aCoord.y - mPositionOffset.y)});
// }

void
gui::BasicObject::setScale(const dom::Pair<float>& aCoord) noexcept
{
    mSprite.setScale({float(aCoord.x), float(aCoord.y)});

    // mPositionOffset.x = mSprite.getGlobalBounds().height / 2;
    // mPositionOffset.y = mSprite.getGlobalBounds().width / 2;
}

gui::BasicObject::PositionUnion
gui::BasicObject::getPosition() const noexcept
{
    return {mSprite.getPosition()};
}

// void
// gui::BasicObject::centrateViewOnObject(str_const_ref aViewName)
// {
//     sf_2f_val coord;
//     if (thisIsSprite) coord = thisToDrawable->getSpritePosition();
//     else coord = thisToWritable->getTextPosition();
//     if (aViewName.empty())
//     {
//         gui::Window::globalWindow.centrateView(mViewNumber, coord);
//     }
// }

// bool
// gui::BasicObject::operator<(const BasicObject& aOther) const
// {
//     if (mLayer != aOther.mLayer) return mLayer < aOther.mLayer;
//     return this < &aOther;
// }

// void
// gui::BasicObject::addLayer(const dom::Pair<const char*, layer_type>&
// aLayer)
// {
//     addLayer(std::vector<dom::Pair<const char*, layer_type>>{aLayer});
// }

// void
// gui::BasicObject::addLayer(
//     const std::vector<dom::Pair<const char*, layer_type>>& aLayerArray)
// {
//     addComponentToDictionary(globalLayerNumbers, aLayerArray);
// }

// void
// gui::BasicObject::setType(GuiObjectType aType)
// {
//     mType = GuiObjectType(sint_32(mType) | sint_32(aType));
// }

// void
// gui::BasicObject::setLayer(str_const_ref aLayerName)
// {
//     mLayer = getComponentNumber(globalLayerNumbers, aLayerName);
// }

// void
// gui::BasicObject::setView(str_const_ref aViewName)
// {
//     mViewNumber = gui::Window::globalWindow.getViewNumber(aViewName);
// }

gui::BasicObject::PositionUnion::operator sf_2f_val() const noexcept
{
    return sfmlPos;
}

gui::BasicObject::PositionUnion::operator dom::Pair<float>() const noexcept
{
    return {sfmlPos.x, sfmlPos.y};
}

// void
// gui::BasicObject::addComponentToDictionary(
//     std::map<str_val, layer_type>& aDictionary,
//     const std::vector<dom::Pair<const char*, layer_type>>& aComponentArray)
// {
//     for (auto& newComponent : aComponentArray)
//     {
// #ifdef _DBG_
//         for (auto& existComponent : aDictionary)
//         {
//             if (existComponent.second == newComponent.second)
//             {
//                 dom::ErrorMessages::writeError(
//                     "Component_number_is_already_occupied_in_dictionary",
//                     "Component_name:", newComponent.first,
//                     "Component_number:", sint_32(newComponent.second),
//                     "Existing_component_name:", existComponent.first);
//             }
//         }
// #endif

//         aDictionary[newComponent.first] = newComponent.second;
//     }
// }

// layer_type
// gui::BasicObject::getComponentNumber(
//     const std::map<str_val, layer_type>& aDictionary,
//     str_const_ref aComponentName)
// {
//     auto result = aDictionary.find(aComponentName);
//     if (result == aDictionary.end())
//     {
// #ifdef _DBG_
//         dom::ErrorMessages::writeError("Dictionary_lack_the_component",
//                                        "Component_name:", aComponentName);
// #endif
//         result = globalLayerNumbers.find("Default");
//     }
//     return result->second;
// }

// bool
// gui::BasicObjectComparator::operator()(BasicObject* a,
//                                          BasicObject* b) const
// {
//     return (*((BasicObject*)a)) < (*((BasicObject*)b));
// }
