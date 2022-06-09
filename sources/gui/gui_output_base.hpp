#ifndef GUI_OUTPUT_BASE_H
#define GUI_OUTPUT_BASE_H

#include <vector>

#include "domain/type.hpp"
#include "domain/pair.hpp"
#include "domain/string.hpp"
#include "domain/error_message.hpp"

#include "logic/basic_object.hpp"

#include "type.hpp"

#define DRAWABLE_TAG "Drawable"s

namespace gui
{
	class GuiOutputBase : virtual public lgc::BasicObject
	{
		struct PositionUnion;

	public:
		enum class GuiObjectType
		{
			NUN = 0,
			SPRITE = 1,
			TEXT = 2,
			SPRITE_AND_TEXT = 3
		};

		GuiOutputBase();
		virtual ~GuiOutputBase() = default;
		void create();

		virtual void draw();

		void move			(dom::Pair<float> aCoord);
		void setPosition	(dom::Pair<float> aCoord);
		void resetPosition	(dom::Pair<float> aCoord);
		void setScale		(dom::Pair<float> aCoord);

		PositionUnion getPosition();

		void centrateViewOnObject(str_const_ref aViewName = "");

		bool operator<(const GuiOutputBase& aOther) const;

		static void addLayer(str_const_ref aName, layer_type& aLayerNumber);
		static void addLayer(const dom::Pair<const char*, layer_type>& aLayer);
		static void addLayer(const std::vector<dom::Pair<const char*, layer_type>>& aLayerArray);

	protected:
		void setType	(GuiObjectType aType);
		void setLayer	(str_const_ref aLayerName);
		void setView	(str_const_ref aViewName);

	private:
		GuiObjectType		mType;
		layer_type			mLayer;
		view_type			mViewNumber;

		static std::map<str_val, layer_type> globalLayerNumbers;

		struct PositionUnion
		{
			sf_2f_val sfmlPos;

			operator sf_2f_val();
			operator dom::Pair<float>();
		};	

		static void addComponentToDictionary
		(
			std::map<str_val, layer_type>& aDictionary,
			const std::vector<dom::Pair<const char*, layer_type>>& aComponentArray
		);

		static layer_type getComponentNumber
		(
			const std::map<str_val, layer_type>& aDictionary,
			str_const_ref aComponentName
		);
	};
	
	struct GuiOutputBaseComparator {
		bool operator() (GuiOutputBase* a, GuiOutputBase* b) const;
	};

	typedef std::set<gui::GuiOutputBase*, gui::GuiOutputBaseComparator> DraweblesSet;
}

#endif // !GUI_OUTPUT_BASE_H