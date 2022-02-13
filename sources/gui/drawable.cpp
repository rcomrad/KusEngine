#include "gui/drawable.hpp"

//Drawable::Drawable(std::string aTexturePath, sf::RenderWindow& aWindow) :
//    mWindow(aWindow)
sr::Drawable::Drawable(std::string aTexturePath, uint_8 aLayer) :
    mLayer      (aLayer)
{
    mTexture.loadFromFile(aTexturePath);
    mSprite.setTexture(mTexture);

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
}

sr::Drawable::~Drawable(){}

void 
//Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) const
sr::Drawable::draw()
{
    //states.transform *= getTransform();

    //// Render the inside
    //states.texture = m_texture;
    //target.draw(m_vertices, states);

    //// Render the outline
    //if (m_outlineThickness != 0)
    //{
    //    states.texture = nullptr;
    //    target.draw(m_outlineVertices, states);
    //}

    Window::allWindow.draw(mSprite);
}

bool 
sr::Drawable::operator<(const Drawable& aOther) const
{
    if (mLayer == aOther.mLayer) return this < &aOther;
    return mLayer < aOther.mLayer;
}

bool 
sr::DrawableComparator::operator() (Drawable* a, Drawable* b) const {
    return (*a) < (*b);
}

void
sr::Drawable::moveSprite(Pair<float> aCoord)
{
    mSprite.move
        ({
            (aCoord.x),
            (aCoord.y)
        });
}

void
sr::Drawable::resetSprite(Pair<float> aCoord)
{
    mSprite.setPosition
    ({
        (aCoord.x - mCoordOffset.x),
        (aCoord.y - mCoordOffset.y)
        });
}


void
sr::Drawable::setScale(Pair<float> aCoord)
{
    mSprite.setScale({ float(aCoord.x), float(aCoord.y) });

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
}

Pair<float>
sr::Drawable::getPosition()
{
    sf::Vector2f pos = mSprite.getPosition();
    return  { (mCoordOffset.x + pos.x),
        (mCoordOffset.y + pos.y) };
}