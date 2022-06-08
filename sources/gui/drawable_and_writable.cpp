#include "drawable_and_writable.hpp"

gui::DrawableAndWritable::DrawableAndWritable
(
   std::string		aTexturePath, 
   std::string		aFontPath
) :
    Drawable      (aTexturePath),
    Writable      (aFontPath)
{}

gui::DrawableAndWritable::DrawableAndWritable
(
   std::string		aTexturePath
) :
    Drawable      (aTexturePath)
{}

void
gui::DrawableAndWritable::create()
{
    this->GuiOutputBase::create();
}