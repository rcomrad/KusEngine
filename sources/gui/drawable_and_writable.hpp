//#ifndef DRAWABLE_AND_WRITABLE_H
//#define DRAWABLE_AND_WRITABLE_H
//
//#include "gui/drawable.hpp"
//#include "gui/writable.hpp"
//
//namespace sr
//{
//	class DrawableAndWritable : public Drawable
//	{
//	public:
//		//Drawable(std::string aTexturePath, sf::RenderWindow& aWindow);
//		DrawableAndWritable
//		(
//			std::string aTexturePath, 
//			std::string aFontPath, 
//			uint_8 aLayer = 0
//		);
//		virtual ~DrawableAndWritable();
//		//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
//		void draw();
//
//	protected:
//		void moveText(Pair<float> aCoord);
//		void resetText(Pair<float> aCoord);
//		void setText(Pair<float> aCoord);
//		Pair<float> getPosition();
//
//	private:
//		sf::Font mFont;
//		sf::Text mText;
//
//		Pair<int> mCoordOffset;
//	};
//}
//
//#endif // !DRAWABLE_AND_WRITABLE_H