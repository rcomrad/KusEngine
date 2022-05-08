#include "drawable_and_writable.hpp"

//Drawable::Drawable(std::string aTexturePath, sf::RenderWindow& aWindow) :
//    mWindow(aWindow)
gui::DrawableAndWritable::DrawableAndWritable
(
   std::string  aTexturePath, 
   std::string  aFontPath,
   uint_8       aLayer
) :
    Drawable      (aTexturePath, aLayer),
    Writable      (aFontPath, aLayer),
    GuiOutputBase (aLayer)
{
   // mFont.loadFromFile(aTexturePath);
   // mText.setFont(mFont);

   // mCoordOffset.x = 100;
   // mCoordOffset.y = 100;
}

gui::DrawableAndWritable::~DrawableAndWritable() {}

//void
//Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) const
// gui::DrawableAndWritable::draw()
// {
//    //states.transform *= getTransform();

//    //// Render the inside
//    //states.texture = m_texture;
//    //target.draw(m_vertices, states);

//    //// Render the outline
//    //if (m_outlineThickness != 0)
//    //{
//    //    states.texture = nullptr;
//    //    target.draw(m_outlineVertices, states);
//    //}

//    Window::allWindow.draw(mText);
// }

// void
// gui::DrawableAndWritable::moveText(dom::Pair<float> aCoord)
// {
//    mText.move
//    ({
//        (aCoord.x),
//        (aCoord.y)
//        });
// }

// void
// gui::DrawableAndWritable::resetText(dom::Pair<float> aCoord)
// {
//    mText.setPosition
//    ({
//        (aCoord.x - mCoordOffset.x),
//        (aCoord.y - mCoordOffset.y)
//    });
// }


// void
// gui::DrawableAndWritable::setText(dom::Pair<float> aCoord)
// {
//    mText.setScale({ float(aCoord.x), float(aCoord.y) });

//    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
//    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
// }

// dom::Pair<float>
// gui::DrawableAndWritable::getPosition()
// {
//    sf::Vector2f pos = mText.getPosition();
//    return  { (mCoordOffset.x + pos.x),
//        (mCoordOffset.y + pos.y) };
// }