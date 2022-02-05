#include "drawable.hpp"

//Drawable::Drawable(std::string aTexturePath, sf::RenderWindow& aWindow) :
//    mWindow(aWindow)
MyDrawable::MyDrawable(std::string aTexturePath, uint_8 aLayer) :
    mLayer      (aLayer)
{
    mTexture.loadFromFile(aTexturePath);
    mSprite.setTexture(mTexture);

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
}

MyDrawable::~MyDrawable(){}

void 
//Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) const
MyDrawable::draw()
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

    mWindow.draw(mSprite);
}

bool 
MyDrawable::operator<(const MyDrawable& aOther) const
{
    if (mLayer == aOther.mLayer) return this < &aOther;
    return mLayer < aOther.mLayer;
}

bool 
DrawableComparator::operator() (MyDrawable* a, MyDrawable* b) const {
    return (*a) < (*b);
}

void
MyDrawable::moveSprite(Pair<float> aCoord)
{
    mSprite.move
        ({
            (aCoord.x),
            (aCoord.y)
        });
}

void
MyDrawable::resetSprite(Pair<float> aCoord)
{
    mSprite.setPosition
    ({
        (aCoord.x - mCoordOffset.x),
        (aCoord.y - mCoordOffset.y)
        });
}


void
MyDrawable::setScale(Pair<float> aCoord)
{
    mSprite.setScale({ float(aCoord.x), float(aCoord.y) });

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
}

Pair<float>
MyDrawable::getPosition()
{
    sf::Vector2f pos = mSprite.getPosition();
    return  { (mCoordOffset.x + pos.x),
        (mCoordOffset.y + pos.y) };
}