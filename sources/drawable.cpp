#include "drawable.hpp"

//Drawable::Drawable(std::string aTexturePath, sf::RenderWindow& aWindow) :
//    mWindow(aWindow)
MyDrawable::MyDrawable(std::string aTexturePath, uint_8 aLayer) :
    mLayer      (aLayer)
{
    mTexture.loadFromFile(aTexturePath);
    mSprite.setTexture(mTexture);
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